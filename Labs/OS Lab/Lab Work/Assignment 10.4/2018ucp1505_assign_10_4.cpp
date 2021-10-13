#include<bits/stdc++.h>
using namespace std;

// Printing the memory block
void print(char mem[]){
	unordered_map<char,int> m;
	for(int i=0;i<16;i++){
		for(int j=0;j<16;j++){
			cout<<mem[16*i+j];
			if(mem[16*i+j]!='*'){
				m[mem[16*i+j]]++;
			}
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;
}

int main(){

	// Reading the file
	FILE *fptr;
	char filename[100];
	cout<<"Enter the filename to open"<<endl;
	cin>>filename;
	
	fptr = fopen(filename,"r");
	if(!fptr){
		cout<<"Unable to open file.."<<endl;
		return -1;
	}
	
	// Declaring and Initializing the memory to empty blocks
	char mem[256];
	for(int i=0;i<256;i++){
		mem[i] = '*';
	}
	
	// for storing links of data block
	unordered_map<int,int> linked;
	
	// For storing indexes of the file in the respective order
	unordered_map<char,vector<int>> indexed;
	
	// For storing the start and end position of linked blocks
	unordered_map<char,pair<int,int>> startPos;
	
	// For storing the size of the file
	unordered_map<char,int> filesize;
	
	// For storing the index block which stores the data block address
	unordered_map<char,int> indexMem;
	
	while(!feof(fptr)){
	
		// Reading from file
		char filename,operation;
		int size;
		fscanf(fptr,"%c %c %d \n",&filename,&operation,&size);
		printf("%c %c %d \n",filename,operation,size);
		
		// Creating operation
		if(operation == 'C'){
			int index = -1;
			int supp = 0;
			filesize[filename] = size;
			do{
				index = (supp)%256;
				supp++;
			}while(mem[index]!='*');
			
			// Indexed
			mem[index] = tolower(filename);
			indexMem[tolower(filename)] = index;
			
			int start = -1,end = -1,prev = -1;
			for(int i=0;i<size;i++){
				int t = (supp)%256;
				supp++;
				while(mem[t] != '*'){
					t = (supp)%256;
					supp++;
				}
				mem[t] = filename;
				if(start == -1){
					start = t;
				}
				end = t;
				if(prev!=-1)
					linked[prev] = t;
				indexed[filename].push_back(t);
				prev = t;
			}
			startPos[filename] = {start,end};
		}
		// Updating operation
		else if(operation == 'M'){
			// If file doesnot exits no such update.
			if(filesize.find(filename) == filesize.end())
				cout<<"File doesnot exits"<<endl;
			else{
				int oldsize = filesize[filename];
				int start = startPos[filename].first;
				// If earlier the size is large we have to delete some blocks
				if(oldsize > size){
					for(int i=1;i<size;i++){
						start = linked[start];	
					}
					startPos[filename].second = start;
					int temp = linked[start];
					while(linked[temp]){
						int t = temp;
						mem[t] = '*';
						temp = linked[temp];
						linked.erase(t);
					}
					mem[temp] = '*';
					int left = oldsize - size;
					while(left--){
						indexed[filename].pop_back();
					}
				}
				// If earlier the size is small we have to insert some blocks
				else if(oldsize < size){
					int supp = 0;
					int prev = startPos[filename].second;
					for(int i=oldsize;i<size;i++){
						int t = (supp)%256;
						supp++;
						while(mem[supp] != '*'){
							t = (supp)%256;
							supp++;
						}
						mem[t] = filename;
						startPos[filename].second = t;
						if(prev!=-1)
							linked[prev] = t;
						indexed[filename].push_back(t);
						prev = t;
					}
				}
				filesize[filename] = size;		
			}
		}
		// Deleting operation
		else if(operation == 'D'){
			int size = filesize[filename];
			int start = startPos[filename].first;
			int end = startPos[filename].second;
			
			// Unlink the list
			int temp = start;
			while(linked[temp]){
				int t = temp;
				mem[t] = '*';
				temp = linked[temp];
				linked.erase(t);
			}
			// Update memory
			mem[temp] = '*';
			
			// Remove traces
			indexed.erase(filename);
			filesize.erase(filename);
			startPos.erase(filename); 
			temp = indexMem[tolower(filename)];
			mem[temp] = '*';
			indexMem.erase(tolower(filename));
		}
		else{
			cout<<"Invalid Operation Chosen"<<endl;
		}
		
		// Printing the status of the memory.
		cout<<"Here lower case are for indexed block and upper case are for data block"<<endl;
		cout<<"Memory view"<<endl;
		print(mem);
	}
	
	return 0;
}
