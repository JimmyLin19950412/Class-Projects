//Name: Jimmy Lin
//Assignment: Memory Allocation
//Date: 11/12/17
//COMPILED USING: g++ -std=c++11 

#include<iostream>
#include<stdexcept>
#include<vector>
#include<fstream>

using namespace std;

class firstFit
{
	private:
		//holds size of pool
		static const size_t poolSize = 1024;
		//initailzies with 0, meaning its free
		int pool[poolSize] = { };
		size_t total = poolSize;
		//holds number of chunks in pool
		int chunks = 0;
		//holds temp chunk size
		int tempChunkSize = 0;
		//holds minimum chunk value. initialize at maximum size so it can be further reduced
		int min = poolSize;
		//holds maximum chunk value. initialize at minimum size so it can be further increased
		int max = 0;
		bool newChunk = true;
		
	public:
		//allocates
		int * allocate(size_t bytes) {
			//loops through entire pool array to find space
			for(int i = 0; i <= poolSize-bytes-1; i++) {
				//seeing if there is space in pool array to allocate
				for(int j = 0; j <= bytes-1; j++) {
					//if the current slot is already allocated
					if(pool[i+j] != 0) {
						//exit inner loop
						break;
					}
					//if the current slot is not allocated and j = bytes (reached end of loop) allocate spaces
					else if(j+1 == bytes){
						//before allocating, write to file
						cout<<"Allocating "<<bytes<<" bytes"<<endl;
						//loops through entire pool array to determine the amount of chunks and their sizes
						for(int z = 0; z <= poolSize-1; z++) {
							//if current position is not a 0, meaning not free
							if(pool[z] != 0) {
								//newChunk is now true, so the next 0 is considered a new chunk
								newChunk = true;
							}
							//if both newChunk is true and the current position in pool is 0, meaning free, then it is considered a new chunk
							if(newChunk == true && pool[z] == 0) {
								chunks++;
								//set newChunk to false, any further consecutive 0's do not count as a new chunk
								newChunk = false;
							}
							//if newChunk is false, meaning curren position in pool is 0, meaning its free,
							if(newChunk == false) {
								tempChunkSize++;
								if(z+1 != poolSize-1) {
									if(pool[z+1] !=0) {
										if(tempChunkSize < min) {
											min = tempChunkSize;
										}
										if(tempChunkSize > max) {
											max = tempChunkSize;
										}
										tempChunkSize = 0;
									}
								}
							}
						}
						//looping through pool and alloating space
						for(int z = 0; z <= bytes-1; z++) {
							//change current position to bytes, meaning its allocated
							pool[i+z] = bytes;
						}
						//outputs to file
						//intiialize firstFitFile and appends to it
						ofstream firstFitFile("firstFitFile.txt", ios_base::app);
						firstFitFile<<total<<", "<<chunks<<", "<<min<<", "<<max<<endl;
						firstFitFile.close();
						//reset chunks
						chunks = 0;
						//reset min 
						min = poolSize;
						//reset max
						max = 0;
						//adjust total with new bytes in array
						total = total - bytes;
						//return pointer from position i, where the allocating began
						return &pool[i];
					}
				}
			}
			//if it gets this far, assume not enough space
			cout<<"Could not allocate "<<bytes<<" bytes"<<endl;
			return nullptr;
		}
			
		//deallocates
		void deallocate(int * address) {
			//holds position to start deallocating
			int position = 0;
			//if address is a nullptr, its pointing to no values. leave
			if(address == nullptr) {
				cout<<"Could not deallocate"<<endl;
				return;
			}
			//holds value of *address
			int value = *address;
			//if address is a nullptr, its pointing to no values. leave
			if(address == nullptr) {
				return;
			}
			//for loop that loops through entire pool array
			for(int i = 0; i <= poolSize-1; i++) {
				//if address is the same as the address in pool[i] then correct position
				if(address == &pool[i]) {
					break;
				}
				position++;
			}
			//loops through entire pool array to determine the amount of chunks and their sizes
			for(int z = 0; z <= poolSize-1; z++) {
				//if current position is not a 0, meaning not free
				if(pool[z] != 0) {
					//newChunk is now true, so the next 0 is considered a new chunk
					newChunk = true;
				}
				//if both newChunk is true and the current position in pool is 0, meaning free, then it is considered a new chunk
				if(newChunk == true && pool[z] == 0) {
					chunks++;
					//set newChunk to false, any further consecutive 0's do not count as a new chunk
					newChunk = false;
				}
				//if newChunk is false, meaning curren position in pool is 0, meaning its free,
				if(newChunk == false) {
					tempChunkSize++;
					if(z+1 != poolSize-1) {
						if(pool[z+1] !=0) {
							if(tempChunkSize < min) {
								min = tempChunkSize;
							}
							if(tempChunkSize > max) {
								max = tempChunkSize;
							}
							tempChunkSize = 0;
						}
					}
				}
			}
			//intiialize firstFitFile and appends to it
			ofstream firstFitFile("firstFitFile.txt", ios_base::app);
			firstFitFile<<total<<", "<<chunks<<", "<<min<<", "<<max<<endl;
			firstFitFile.close();
			//reset chunks
			chunks = 0;
			//reset min 
			min = poolSize;
			//reset max
			max = 0;
			//optains value pointer is pointing to
			cout<<"Deallocating "<<*address<<" bytes"<<endl;
			//add amount of deallocation back to total
			total = total + *address;
			//for loop that starts at position and loops until it reaches the amount of *address
			for(int i = position; i <= position+value-1; i++) {
				pool[i] = 0;
			}
			//reset position
			position = 0;
		}
};

class nextFit
{
	private:
		//holds size of pool
		static const size_t poolSize = 1024;
		//initailzies with 0, meaning its free
		int pool[poolSize] = { };
		size_t total = poolSize;
		//holds number of chunks in pool
		int chunks = 0;
		//holds temp chunk size
		int tempChunkSize = 0;
		//holds minimum chunk value. initialize at maximum size so it can be further reduced
		int min = poolSize;
		//holds maximum chunk value. initialize at minimum size so it can be further increased
		int max = 0;
		bool newChunk = true;
		//holds last pointer position that was allocated. initializes to the first element of pool
		int * lastLocation = &pool[0];
		//holds index position of pool that was last allocated
		int lastLocationPosition;
		
	public:
		//allocations
		int * allocate(size_t bytes) {
			//finds index of pool that was last allocated
			for(int i = 0; i <= poolSize-1; i++) {
				//if address is the same as the address in pool[i] then correct position
				if(lastLocation == &pool[i]) {
					lastLocationPosition = i;
					break;
				}
			}
			//loops from last allocated position to end of pool array
			for(int i = lastLocationPosition; i <= poolSize-bytes-1; i++) {
				//seeing if there is space in pool array to allocate
				for(int j = 0; j <= bytes-1; j++) {
					//if the current slot is already allocated
					if(pool[i+j] != 0) {
						//exit inner loop
						break;
					}
					//if the current slot is not allocated and j = bytes (reached end of loop) allocate spaces
					else if(j+1 == bytes) {
						//before allocating, write to file
						cout<<"Allocating "<<bytes<<" bytes"<<endl;
						//loops through entire pool array to determine the amount of chunks and their sizes
						for(int z = 0; z <= poolSize-1; z++) {
							//if current position is not a 0, meaning not free
							if(pool[z] != 0) {
								//newChunk is now true, so the next 0 is considered a new chunk
								newChunk = true;
							}
							//if both newChunk is true and the current position in pool is 0, meaning free, then it is considered a new chunk
							if(newChunk == true && pool[z] == 0) {
								chunks++;
								//set newChunk to false, any further consecutive 0's do not count as a new chunk
								newChunk = false;
							}
							//if newChunk is false, meaning curren position in pool is 0, meaning its free,
							if(newChunk == false) {
								tempChunkSize++;
								if(z+1 != poolSize-1) {
									if(pool[z+1] !=0) {
										if(tempChunkSize < min) {
											min = tempChunkSize;
										}
										if(tempChunkSize > max) {
											max = tempChunkSize;
										}
										tempChunkSize = 0;
									}
								}
							}
						}
						//looping through pool and alloating space
						for(int z = 0; z <= bytes-1; z++) {
							//change current position to bytes, meaning its allocated
							pool[i+z] = bytes;
							//updates last location that was allocated
							lastLocation = &pool[i+z];
						}
						//outputs to file
						//intiialize firstFitFile and appends to it
						ofstream nextFitFile("nextFitFile.txt", ios_base::app);
						nextFitFile<<total<<", "<<chunks<<", "<<min<<", "<<max<<endl;
						nextFitFile.close();
						//reset chunks
						chunks = 0;
						//reset min 
						min = poolSize;
						//reset max
						max = 0;
						//adjust total with new bytes in array
						total = total - bytes;
						//return pointer from position i, where the allocating began
						return &pool[i];
					}
				}
			}
			//once the previous loop reaches end of array, start from beginning of array to see if theres enough space before the last location allocated
			for(int i = 0; i <= lastLocationPosition-1; i++) {
				//seeing if there is space in pool array to allocate
				for(int j = 0; j <= bytes-1; j++) {
					//if the current slot is already allocated
					if(pool[i+j] != 0) {
						//exit inner loop
						break;
					}
					//if the current slot is not allocated and j = bytes (reached end of loop) allocate spaces
					else if(j+1 == bytes) {
						//before allocating, write to file
						cout<<"Allocating "<<bytes<<" bytes"<<endl;
						//loops through entire pool array to determine the amount of chunks and their sizes
						for(int z = 0; z <= poolSize-1; z++) {
							//if current position is not a 0, meaning not free
							if(pool[z] != 0) {
								//newChunk is now true, so the next 0 is considered a new chunk
								newChunk = true;
							}
							//if both newChunk is true and the current position in pool is 0, meaning free, then it is considered a new chunk
							if(newChunk == true && pool[z] == 0) {
								chunks++;
								//set newChunk to false, any further consecutive 0's do not count as a new chunk
								newChunk = false;
							}
							//if newChunk is false, meaning curren position in pool is 0, meaning its free,
							if(newChunk == false) {
								tempChunkSize++;
								if(z+1 != poolSize-1) {
									if(pool[z+1] !=0) {
										if(tempChunkSize < min) {
											min = tempChunkSize;
										}
										if(tempChunkSize > max) {
											max = tempChunkSize;
										}
										tempChunkSize = 0;
									}
								}
							}
						}
						//looping through pool and alloating space
						for(int z = 0; z <= bytes-1; z++) {
							//change current position to bytes, meaning its allocated
							pool[i+z] = bytes;
							//updates last location that was allocated
							lastLocation = &pool[i+z];
						}
						//outputs to file
						//intiialize firstFitFile and appends to it
						ofstream nextFitFile("nextFitFile.txt", ios_base::app);
						nextFitFile<<total<<", "<<chunks<<", "<<min<<", "<<max<<endl;
						nextFitFile.close();
						//reset chunks
						chunks = 0;
						//reset min 
						min = poolSize;
						//reset max
						max = 0;
						//adjust total with new bytes in array
						total = total - bytes;
						//return pointer from position i, where the allocating began
						return &pool[i];
					}
				}
			}
			//if it gets this far, assume not enough space
			cout<<"Could not allocate "<<bytes<<" bytes"<<endl;
			return nullptr;
		}
		
		//deallocates
		void deallocate(int * address) {
			//holds position to start deallocating
			int position = 0;
			//if address is a nullptr, its pointing to no values. leave
			if(address == nullptr) {
				cout<<"Could not deallocate"<<endl;
				return;
			}
			//holds value of *address
			int value = *address;
			//if address is a nullptr, its pointing to no values. leave
			if(address == nullptr) {
				return;
			}
			//for loop that loops through entire pool array
			for(int i = 0; i <= poolSize-1; i++) {
				//if address is the same as the address in pool[i] then correct position
				if(address == &pool[i]) {
					position = i;
					break;
				}
			}
			//loops through entire pool array to determine the amount of chunks and their sizes
			for(int z = 0; z <= poolSize-1; z++) {
				//if current position is not a 0, meaning not free
				if(pool[z] != 0) {
					//newChunk is now true, so the next 0 is considered a new chunk
					newChunk = true;
				}
				//if both newChunk is true and the current position in pool is 0, meaning free, then it is considered a new chunk
				if(newChunk == true && pool[z] == 0) {
					chunks++;
					//set newChunk to false, any further consecutive 0's do not count as a new chunk
					newChunk = false;
				}
				//if newChunk is false, meaning curren position in pool is 0, meaning its free,
				if(newChunk == false) {
					tempChunkSize++;
					if(z+1 != poolSize-1) {
						if(pool[z+1] !=0) {
							if(tempChunkSize < min) {
								min = tempChunkSize;
							}
							if(tempChunkSize > max) {
								max = tempChunkSize;
							}
							tempChunkSize = 0;
						}
					}
				}
			}
			//intiialize firstFitFile and appends to it
			ofstream nextFitFile("nextFitFile.txt", ios_base::app);
			nextFitFile<<total<<", "<<chunks<<", "<<min<<", "<<max<<endl;
			nextFitFile.close();
			//reset chunks
			chunks = 0;
			//reset min 
			min = poolSize;
			//reset max
			max = 0;
			//optains value pointer is pointing to
			cout<<"Deallocating "<<*address<<" bytes"<<endl;
			//add amount of deallocation back to total
			total = total + *address;
			//for loop that starts at position and loops until it reaches the amount of *address
			for(int i = position; i <= position+value-1; i++) {
				pool[i] = 0;
			}
			//reset position
			position = 0;
		}
};

class bestFit
{
	private:
		//holds size of pool
		static const size_t poolSize = 1024;
		//initailzies with 0, meaning its free
		int pool[poolSize] = { };
		size_t total = poolSize;
		//holds number of chunks in pool
		int chunks = 0;
		//holds temp chunk size
		int tempChunkSize = 0;
		//holds minimum chunk value. initialize at maximum size so it can be further reduced
		int min = poolSize;
		//holds maximum chunk value. initialize at minimum size so it can be further increased
		int max = 0;
		bool newChunk = true;
		//holds index for temporary best fit location in pool array
		int lastLocationPosition;
		
		public:
		
		//allocates
		int * allocate(size_t bytes) {
			//holds temp size in allocate array to determine best fit. Initialize poolSize so anything can be smaller then it
			int tempMinSize = poolSize+1;
			//boolean to determine if byte can fit in memory array pool
			bool canFit = false;
			//loops through entire pool array to find space
			for(int i = 0; i <= poolSize-bytes-1; i++) {
				//used in while loop
				int k = 0;
				//while loop that counts how many free memory are in array
				while((k+i) < poolSize-bytes-1) {
					if(pool[k+i] != 0) {
						break;
					}
					k++;
				}
				//if k, number of free btyes, is greater then or equal to bytes then it can fit
				//k has to also be less than tempMinSize or it wont be best fit
				if(k >= bytes && k < tempMinSize) {
					tempMinSize = k;
					lastLocationPosition = i;
					canFit = true;
				}
			}
			//byte can fit in memory
			if(canFit == true) {
				//before allocating, write to file
				cout<<"Allocating "<<bytes<<" bytes"<<endl;
				//loops through entire pool array to determine the amount of chunks and their sizes
				for(int z = 0; z <= poolSize-1; z++) {
				//if current position is not a 0, meaning not free
					if(pool[z] != 0) {
						//newChunk is now true, so the next 0 is considered a new chunk
						newChunk = true;
					}
					//if both newChunk is true and the current position in pool is 0, meaning free, then it is considered a new chunk
					if(newChunk == true && pool[z] == 0) {
						chunks++;
						//set newChunk to false, any further consecutive 0's do not count as a new chunk
						newChunk = false;
					}
					//if newChunk is false, meaning curren position in pool is 0, meaning its free,
					if(newChunk == false) {
						tempChunkSize++;
						if(z+1 != poolSize-1) {
							if(pool[z+1] !=0) {
								if(tempChunkSize < min) {
									min = tempChunkSize;
								}
								if(tempChunkSize > max) {
									max = tempChunkSize;
								}
								tempChunkSize = 0;
							}
						}
					}
				}
				//looping through pool and alloating space
				for(int z = 0; z <= bytes-1; z++) {
					//change current position to bytes, meaning its allocated
					pool[lastLocationPosition+z] = bytes;
				}
				//outputs to file
				//intiialize firstFitFile and appends to it
				ofstream bestFitFile("bestFitFile.txt", ios_base::app);
				bestFitFile<<total<<", "<<chunks<<", "<<min<<", "<<max<<endl;
				bestFitFile.close();
				//reset chunks
				chunks = 0;
				//reset min 
				min = poolSize;
				//reset max
				max = 0;
				//adjust total with new bytes in array
				total = total - bytes;
				//return pointer from position i, where the allocating began
				return &pool[lastLocationPosition];
			}
			//byte cant fit in memory
			else {
				//if it gets this far, assume not enough space
				cout<<"Could not allocate "<<bytes<<" bytes"<<endl;
				return nullptr;
			}
		}
		
		//deallocates
		void deallocate(int * address) {
			//holds position to start deallocating
			int position = 0;
			//if address is a nullptr, its pointing to no values. leave
			if(address == nullptr) {
				cout<<"Could not deallocate"<<endl;
				return;
			}
			//holds value of *address
			int value = *address;
			//for loop that loops through entire pool array
			for(int i = 0; i <= poolSize-1; i++) {
				//if address is the same as the address in pool[i] then correct position
				if(address == &pool[i]) {
					break;
				}
				position++;
			}
			//loops through entire pool array to determine the amount of chunks and their sizes
			for(int z = 0; z <= poolSize-1; z++) {
				//if current position is not a 0, meaning not free
				if(pool[z] != 0) {
					//newChunk is now true, so the next 0 is considered a new chunk
					newChunk = true;
				}
				//if both newChunk is true and the current position in pool is 0, meaning free, then it is considered a new chunk
				if(newChunk == true && pool[z] == 0) {
					chunks++;
					//set newChunk to false, any further consecutive 0's do not count as a new chunk
					newChunk = false;
				}
				//if newChunk is false, meaning curren position in pool is 0, meaning its free,
				if(newChunk == false) {
					tempChunkSize++;
					if(z+1 != poolSize-1) {
						if(pool[z+1] !=0) {
							if(tempChunkSize < min) {
								min = tempChunkSize;
							}
							if(tempChunkSize > max) {
								max = tempChunkSize;
							}
							tempChunkSize = 0;
						}
					}
				}
			}
			//intiialize firstFitFile and appends to it
			ofstream firstFitFile("firstFitFile.txt", ios_base::app);
			firstFitFile<<total<<", "<<chunks<<", "<<min<<", "<<max<<endl;
			firstFitFile.close();
			//reset chunks
			chunks = 0;
			//reset min 
			min = poolSize;
			//reset max
			max = 0;
			//optains value pointer is pointing to
			cout<<"Deallocating "<<*address<<" bytes"<<endl;
			//add amount of deallocation back to total
			total = total + *address;
			//for loop that starts at position and loops until it reaches the amount of *address
			for(int i = position; i <= position+value-1; i++) {
				pool[i] = 0;
			}
			//reset position
			position = 0;
		}
};

int main()
{
	//initialize vector to hold allocations
	vector<int*> firstFitAllocations;
	vector<int*> nextFitAllocations;
	vector<int*> bestFitAllocations;
	//initialize first fit allocator
	firstFit firstFitAllocator;
	//initializes next fit allocator
	nextFit nextFitAllocator;
	//initializes best fit allocator
	bestFit bestFitAllocator;
	//temporary
	int tmp;
	//operand to perform a - allocate d - deallocate
	char operand;
	//size to allocate
	int size;
	
	//initialize and open trace file
	ifstream trace("trace.txt");
	
	//---------------------------------First Fit----------------------------------------------
	//if file is open
	if(trace.is_open() == true) {
		//initialize and file to output
		ofstream firstFitFile("firstFitFile.txt");
		firstFitFile<<"Free, Chunks, Min, Max"<<endl;
		//closes firstFitFile
		firstFitFile.close();
		cout<<"---------------First Fit Memory Allocation---------------"<<endl;
		//read from file and assigns them to tmp, operand, size
		while(trace >> tmp && trace >> operand && trace >> size) {
			switch(operand) {
					//allocate
					case 'a':
						//retreive address from function (pool array), place in back of allocations array
						firstFitAllocations.push_back(firstFitAllocator.allocate(size));
						break;
					//deallocate
					case 'd':
						//retreive address from allocations, remove it from pool array
						firstFitAllocator.deallocate(firstFitAllocations[size]);
						//pointer points to null
						firstFitAllocations[size] = nullptr;
						break;
			}
		}
		//closes trace file
		trace.close();
	}
	//cant open file
	else {
		cout<<"Can't locate trace.txt file for first fit"<<endl;
	}
	//---------------------------------End First Fit----------------------------------------------
	
	//---------------------------------Next Fit----------------------------------------------
	//open trace file
	trace.open("trace.txt");
	
	//if file is open
	if(trace.is_open() == true) {
		//initialize and file to output
		ofstream nextFitFile("nextFitFile.txt");
		nextFitFile<<"Free, Chunks, Min, Max"<<endl;
		//closes firstFitFile
		nextFitFile.close();
		cout<<"---------------Next Fit Memory Allocation---------------"<<endl;
		//read from file and assigns them to tmp, operand, size
		while(trace >> tmp && trace >> operand && trace >> size) {
			switch(operand) {
					//allocate
					case 'a':
						//retreive address from function (pool array), place in back of allocations array
						nextFitAllocations.push_back(nextFitAllocator.allocate(size));
						break;
					//deallocate
					case 'd':
						//retreive address from allocations, remove it from pool array
						nextFitAllocator.deallocate(nextFitAllocations[size]);
						//pointer points to null
						nextFitAllocations[size] = nullptr;
						break;
			}
		}
		//closes trace file
		trace.close();
	}
	//cant open file
	else {
		cout<<"Can't locate trace.txt file for next fit"<<endl;
	}
	//---------------------------------End Next Fit----------------------------------------------
	
	//---------------------------------Best Fit----------------------------------------------
	//open trace file
	trace.open("trace.txt");
	
	//if file is open
	if(trace.is_open() == true) {
		//initialize and file to output
		ofstream bestFitFile("bestFitFile.txt");
		bestFitFile<<"Free, Chunks, Min, Max"<<endl;
		//closes firstFitFile
		bestFitFile.close();
		cout<<"---------------Best Fit Memory Allocation---------------"<<endl;
		//read from file and assigns them to tmp, operand, size
		while(trace >> tmp && trace >> operand && trace >> size) {
			switch(operand) {
					//allocate
					case 'a':
						//retreive address from function (pool array), place in back of allocations array
						bestFitAllocations.push_back(bestFitAllocator.allocate(size));
						break;
					//deallocate
					case 'd':
						//retreive address from allocations, remove it from pool array
						bestFitAllocator.deallocate(bestFitAllocations[size]);
						//pointer points to null
						bestFitAllocations[size] = nullptr;
						break;
			}
		}
		//closes trace file
		trace.close();
	}
	//cant open file
	else {
		cout<<"Can't locate trace.txt file for best fit"<<endl;
	}
	//---------------------------------End Best Fit----------------------------------------------

	return 0;
}