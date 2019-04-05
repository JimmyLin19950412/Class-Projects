#include <cstdlib>
#include <iostream>
#include <cerrno>
#include <unistd.h>
#include <list>
#include "mpi.h"

using namespace std;

void master(int p, int tag, int & philsEaten);
void philosopher(int id, int tag);

int main (int argc, char *argv[]) 
{
	int id; //my MPI ID
	int p;  //total MPI processes
	int tag = 1;
	int philsEaten = 0; //num of philosophers that ate. default 0, no philosophers ate
	//  Initialize MPI.
	MPI::Init (argc, argv);
	//  Get the number of processes.
	p = MPI::COMM_WORLD.Get_size();
	//  Determine the rank of this process.
	id = MPI::COMM_WORLD.Get_rank();
	
	if(id == 0) { //Master
		master(p, tag, philsEaten);
	}
	else { //I'm a philosopher
		philosopher(id, tag);
	}
	
	//  Terminate MPI.
	MPI_Finalize();
	return 0;
}

void master (int p, int tag, int & philsEaten)
{
	//msg received from philosopher
	//1 = requesting for fork, requeusting to eat
	//2 = done eating
	int msgIn;
	//msg to send to philosopher, does not matter
	int msgOut = 1;
	MPI::Status status;
	//Queue to put philosophers in if there are not enough forks
	list<int> philQueue;
	
	//array to hold the forks
	int forks[p-1];
	
	//initilaize all forks, they are originally all free
	//0 = free
	//1 = in use
	for(int i = 0; i < p; i++) {
		forks[i] = 0;
	}

	//loop to receive philosopher messages
	//stops when either both queue is empty and all phils ate
	while(philQueue.empty() == false || philsEaten != (p-1)) {
		//receives message from philosophers
		MPI::COMM_WORLD.Recv(&msgIn, 1, MPI::INT, MPI::ANY_SOURCE, tag, status);
		
		//philosopher is requesting for fork, waiting to eat
		if(msgIn == 1) {
			cout<<"Received Request to eat from Philosopher "<<status.Get_source()<<endl;
			//if forks left and right of phil are free
			if(forks[status.Get_source()%(p-1)] == 0 && forks[status.Get_source()-1] == 0) {
				//forks are now in use
				forks[status.Get_source()%(p-1)] = 1;
				forks[status.Get_source()-1] = 1;
				//send message to philosopher, fork is free
				if(status.Get_source()-1 == 0 && status.Get_source() == p-1) {
					cout<<"Assigning forks "<<p-2<<" and "<<status.Get_source()<<" to Philosopher "<<status.Get_source()<<endl;
				}
				else if(status.Get_source()-1 == 0) {
					cout<<"Assigning forks "<<p-1<<" and "<<status.Get_source()<<" to Philosopher "<<status.Get_source()<<endl;
				}
				else {
					cout<<"Assigning forks "<<status.Get_source()-1<<" and "<<status.Get_source()<<" to Philosopher "<<status.Get_source()<<endl;
				}
				MPI::COMM_WORLD.Send(&msgOut, 1, MPI::INT, status.Get_source(), tag);
			}
			else { //one or more fork is not free
				//put philosopher in wait, queue
				philQueue.push_back(status.Get_source());
				//adds one to numInQueue
				cout<<"Could not process Philosopher "<<status.Get_source()<<"'s request, adding to wait queue"<<endl;
			}
		}
		//philosopher is done eating
		else if(msgIn == 2) {
			//forks are now in use
			forks[status.Get_source()%(p-1)] = 0;
			forks[status.Get_source()-1] = 0;
			cout<<"Received Done Eating from Philosopher "<<status.Get_source()<<endl;
			if(status.Get_source()-1 == 0 && status.Get_source() == p-1) {
				cout<<"Forks "<<p-2<<" and "<<status.Get_source()<<" returned from Philosopher "<<status.Get_source()<<endl;
			}
			else if(status.Get_source()-1 == 0) {
				cout<<"Forks "<<p-1<<" and "<<status.Get_source()<<" returned from Philosopher "<<status.Get_source()<<endl;
			}
			else {
				cout<<"Forks "<<status.Get_source()-1<<" and "<<status.Get_source()<<" returned from Philosopher "<<status.Get_source()<<endl;
			}
			//increase the number of philosophers that ate
			philsEaten++;
			
			//when a fork is returned, check if queue is empty or not
			//if not then see if the philosopher can use the newely returned fork
			if(philQueue.empty() == false) {
				//loop through entire queue to
				for(std::list<int>::iterator i = philQueue.begin(); i != philQueue.end(); i++) {
					//if the forks are free for that philosopher
					if(forks[*i%(p-1)] == 0 && forks[*i-1] == 0) {
						//forks are now in use
						forks[*i%(p-1)] = 1;
						forks[*i-1] = 1;
						//send message to philosopher, fork is free
						if(*i%(p-1) == 0 && *i == p-1) {
							cout<<"Assigning forks "<<p-2<<" and "<<*i<<" to Philosopher "<<*i<<endl;
						}
						else if(*i%(p-1) == 0) {
							cout<<"Assigning forks "<<p-1<<" and "<<*i<<" to Philosopher "<<*i<<endl;
						}
						else if(*i-1 == 0) {
							cout<<"Assigning forks "<<*i%(p-1)<<" and "<<p-1<<" to Philosopher "<<*i<<endl;
						}
						else {
							cout<<"Assigning forks "<<*i%(p-1)<<" and "<<*i-1<<" to Philosopher "<<*i<<endl;
						}
						MPI::COMM_WORLD.Send(&msgOut, 1, MPI::INT, *i, tag);
						//removing from queue
						i = philQueue.erase(i);
					}
				}
			}
		}
	}
}

void philosopher (int id, int tag)
{
	//status of philospher's eat
	bool eat = false;
	//msg to be sent to master
	//DEFAULT: 1 = requesting for fork, waiting to eat
	//2 = done eating, sending forks back
	int msgOut = 1;
	//msg received from master
	int msgIn;
	
	MPI::Status status;
	srand(id + time(NULL)); //ensure different seeds...
	
	//if philosopher has not eaten yet
	if(eat == false) {
		//wait a random amount of time before asking master
		usleep(rand()%100);
		//requesting for fork, tells master philosopher is waiting to eat
		MPI::COMM_WORLD.Send(&msgOut, 1, MPI::INT, 0, tag);
		//waiting for master to respond
		MPI::COMM_WORLD.Recv(&msgIn, 1, MPI::INT, 0, tag, status);
		//wait a random amount of time to eat
		usleep(rand()%100);
		//philosopher is done eating, sending forks back
		msgOut = 2;
		MPI::COMM_WORLD.Send(&msgOut, 1, MPI::INT, 0, tag);
		//philosopher is done eating
		eat = true;
	}
}