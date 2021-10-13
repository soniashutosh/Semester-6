// Readers Writers Probelm

// Fairness Solution

#include<bits/stdc++.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
using namespace std;

sem_t rmutex,resource,serviceQueue;
int readcount = 0;
int writecount = 0;

void* start_write(void* arg){
	while(1){
		int index = *(int*)arg;
		sem_wait(&serviceQueue);
		cout<<"Writer "<<index<<" wants to enter"<<endl;
		sem_wait(&resource);
		sem_post(&serviceQueue);
		cout<<"Writer "<<index<<" starts writing"<<endl;
		sleep(1);
		cout<<"Writer "<<index<<" is Leaving"<<endl;
		sem_post(&resource);
	}
}

void* start_read(void *arg){
	while(1){
		int index = *(int*)arg;
		sem_wait(&serviceQueue);
		sem_wait(&rmutex);
		cout<<"Reader "<<index<<" wants to enter"<<endl;
		readcount++;
		if(readcount==1){
			sem_wait(&resource);
		}
		sem_post(&rmutex);
		sem_post(&serviceQueue);
		cout<<"Reader "<<index<<" starts reading"<<endl;
		sleep(1);
		sem_wait(&rmutex);
		readcount--;
		cout<<"Reader "<<index<<" is Leaving"<<endl;
		if(readcount==0){
			sem_post(&resource);
		}
		sem_post(&rmutex);
	}
}

int main(){
	int readers,writers;
	cout<<"Enter the number of readers and writers: "<<endl;
	cin>>readers>>writers;

	// thread creation
	pthread_t read[readers],write[writers];
	int read_index[readers];
	int write_index[writers];

	// Semaphore initialization
	sem_init(&rmutex,0,1);
	sem_init(&resource,0,1);
	sem_init(&serviceQueue,0,1);

	// thread attribute creation
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);

	// Creation of thread
	for(int i=0;i<readers;i++){
		read_index[i] = i+1;
		void *ptr = &read_index[i];
		int r1 = pthread_create(&read[i],&attr,start_read,ptr);
		if(r1){
			cout<<"Error in creating thread"<<endl;
			exit(-1);
		}
	}

	for(int i=0;i<writers;i++){
		write_index[i] = i+1;
		void *ptr = &write_index[i];
		int r1 = pthread_create(&write[i],&attr,start_write,ptr);
		if(r1){
			cout<<"Error in creating thread"<<endl;
			exit(-1);
		}
	}

	pthread_attr_destroy(&attr); 	

	// Joining of thread
	for(int i=0;i<readers;i++){
		int r1 = pthread_join(read[i],NULL);
		if(r1){
			cout<<"Error in joining thread"<<endl;
			exit(-1);
		}
	}

	for(int i=0;i<writers;i++){
		int r1 = pthread_join(write[i],NULL);
		if(r1){
			cout<<"Error in joining thread"<<endl;
			exit(-1);
		}
	}

	// Exiting thread
	pthread_exit(NULL);

	return 0;
}

