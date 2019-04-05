// Jimmy Lin
// Homework 5
// Date: 10/16/17

#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <fstream>
#include <string>

using namespace std;

//mutex for queue filesToRead
mutex mtxfilesToRead;
//mutex for queue wordCount
mutex mtxwordCount;

//if a human grades this, hi

//looks through files and count how many times a word appears
//filesToRead is the queue of files to read from
//wordCount is the queue of words counted
//word is the word to be counted/look for
void mapper(deque<string> &filesToRead, deque<int> &wordCount, string word);
//add the number of counts together
//wordCount is the queue of words counted
void reducer(deque<int> &wordCount);

int main()
{	
	//4 is the default amount of mappers
	int numMappers = 4;
	//4 is the default amount of reducers
	int numReducers = 4;
	//contains the word the user is requesting to count
	string word;
	//contains the line that file read
	string line;
	//opens file to read from. defualt files.dat
	ifstream myFile("files.dat");
	//creates a queue of files to read in
	deque<string> filesToRead;
	//queue that holds the number of matches of word
	deque<int> wordCount;
	
	//asks user for a word to count
	cout<<"What word do you wish to count?"<<endl;
	cin>>word;
	
	//checks to see of the file opened successfully
	if(myFile.is_open() == true) {
		//reads open file and pushes contents into filesToRead queue
		//getline is true when there is a line to be read
		while(getline(myFile, line)) {
			//adds the line to the end of queue
			filesToRead.push_back(line);
		}
		//closes file
		myFile.close();
	}
	//file did not open correctly
	else {
		cout<<"file.dat was not opened correctly."<<endl;
	}
	
	//creates a thread of arrays to easily construct the threads
	//the size of the array is equal to the number of mappers and reducers threads to be created
	thread mapperThreads[numMappers];
	thread reducerThreads[numReducers];
	
	//initates the threads mapper threads and places them into the array
	for(int i = 0; i < numMappers; i++) {
		//syntax for thread apparently, weird af
		//thread(functionName, first parameter for functionName, second parameter for functionName, etc)
		mapperThreads[i] = thread(mapper, ref(filesToRead), ref(wordCount), word);
	}
	//joins mapping threads. Waits for them to finish
	for(int i = 0; i < numMappers; i++) {
		mapperThreads[i].join();
	}
	//initaites the threads reducer threads and places them into the array
	for(int i = 0; i < numReducers; i++) {
		reducerThreads[i] = thread(reducer, ref(wordCount));
	}
	//joins the reducer threads. Waits for them to finish
	for(int i = 0; i < numReducers; i++) {
		//thread lives matter too!!!!
		//call an end to .join()!!!!
		//threads should be allowed to live!!!!
		reducerThreads[i].join();
	}
	
	cout<<"I get a count of "<<wordCount.front()<<" for the word "<<word<<"."<<endl;
	
	return 0;
}

//looks through files and count how many times a word appears
//filesToRead is the queue of files to read from
//wordCount is the queue of words counted
//word is the word to be counted/look for
void mapper(deque<string> &filesToRead, deque<int> &wordCount, string word)
{
	//while loop that removes a file from queue and counts how many words appear in that file
	//continues until the file is empty
	while(filesToRead.size() != 0) {
		//holds the number of words counted that match the word the user asked
		int count = 0;
		//contains the word read in file
		string wordRead;
		//contains the file located on the top of queue filesToRead
		string topFile;
		//initiates ifstream
		ifstream ifstreamFile;
		
		//locks filesToRead queue so no multiple threads can access the queue
		unique_lock<mutex> lockFile(mtxfilesToRead);
		//assigns the top/front most file in queue filesToRead to topFile
		topFile = filesToRead.front();
		//removes the top/front file in queue filesToRead
		filesToRead.pop_front();
		//unlocks filesToRead so other threads can access
		lockFile.unlock();
		//opens file in topFile
		ifstreamFile.open(topFile);
		if(ifstreamFile.is_open() == true) {
			//while loop that reads a word in file and places it in wordRead
			//while exits when there is no word to be placed into wordRead
			//syntax: file that is opened >> var name
			while(ifstreamFile >> wordRead) {
				//if the wordRead is the same as the word the user asked for
				if(wordRead == word) {
					//increase count by 1
					count++;
				}
			}
			//closes file
			ifstreamFile.close();
			
			//if count is not 0
			//no need to lock/access the queue wordCount if count is 0
			//this hopefully maybe(?) lets other mapper threads who need to access it access it, speeding up the process
			if(count != 0) {
				//locks the queue wordCount so multiple threads cannot acces sit at the same time
				unique_lock<mutex> lockwordCount(mtxwordCount);
				//adds count to queue wordCount
				wordCount.push_back(count);
				//unlocks the queue wordCount so other threads can access it
				lockwordCount.unlock();	
			}
		}
		//else if file did not open correctly
		else {
			cout<<"File"<<topFile<<" could not be opened."<<endl;
		}
	}
}

//add the number of counts together
//wordCount is the queue of words counted
void reducer(deque<int> &wordCount)
{
	//possible solution
	//while(bool == true || wordCount.size() > 1) {
		//while(wordCount.size() > 1) {
			//magic();
		//}
	//}
	//--end possible suoltion
	
	//while loop continuously adds numbers in queue wordCount until there is only 1 number remaining
	while(wordCount.size() > 1) {
		//contains 2 numbers to be added
		int num1;
		int num2;
		
		//locks queue wordCount so multiple threads cannot access the queue wordCount
		unique_lock<mutex> lockReducer(mtxwordCount);
		//puts the top number in queue wordCount into num1
		num1 = wordCount.front();
		//removes the top number in queue wordCount
		wordCount.pop_front();
		//puts the top number in queue wordCount into num2
		num2 = wordCount.front();
		//removes the top number in queue wordCount
		wordCount.pop_front();
		//puts the num1+num2 into the back of queue wordCount
		wordCount.push_back(num1+num2);
		//unlocks queue wordCount so other threads can access the queue wordCount
		lockReducer.unlock();
	}
}