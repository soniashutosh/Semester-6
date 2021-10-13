#include<bits/stdc++.h>
using namespace std;

float findAverageRotationalDelay(float rpm){
	return 30/rpm;
}

int totalSeekTimeUsingCSCAN(int number_of_cylinders,int initial_head_position,vector<int> requests){
	int number_of_requests = requests.size();
	vector<int> right;
	vector<int> left;
	
	left.push_back(0);
	right.push_back(number_of_cylinders-1);
	for(int i=0;i<number_of_requests;i++){
		if(requests[i] < initial_head_position){
			left.push_back(requests[i]);
		}
		else{
			right.push_back(requests[i]);
		}
	}
	
	sort(left.begin(),left.end());
	sort(right.begin(),right.end());
	
	int total_seek_time=0;
	
	total_seek_time = right[right.size()-1] - initial_head_position;
	total_seek_time += right[right.size()-1] - 0;
	total_seek_time += left[left.size()-1];
	
	return total_seek_time;
}

int main(){
	
	FILE *fptr;
	char filename[100];
	cout<<"Enter the filename to open"<<endl;
	cin>>filename;
	
	fptr = fopen(filename,"r");
	if(!fptr){
		cout<<"Unable to open file.."<<endl;
		return -1;
	}
	
	int number_of_cylinder;
	int number_of_sectors;
	int bytes_per_sectors;
	float rpm;
	float average_seek_time;
	int initial_head_position;
	
	if(!feof(fptr)){
		fscanf(fptr,"%d",&number_of_cylinder);
	}
	
	if(!feof(fptr)){
		fscanf(fptr,"%d",&number_of_sectors);
	}
	
	if(!feof(fptr)){
		fscanf(fptr,"%d",&bytes_per_sectors);
	}
	
	if(!feof(fptr)){
		fscanf(fptr,"%f",&rpm);
	}
	
	if(!feof(fptr)){
		fscanf(fptr,"%f",&average_seek_time);
	}
	
	if(!feof(fptr)){
		fscanf(fptr,"%d",&initial_head_position);
	}
	
	vector<int> requests;
	while(!feof(fptr)){
		int request;
		fscanf(fptr,"%d",&request);
		requests.push_back(request);
	}
	
	cout<<endl;
	cout<<"Given"<<endl;
	cout<<"Number of Tracks(cylinder): "<<number_of_cylinder<<endl;
	cout<<"Number of Sectors: "<<number_of_sectors<<endl;
	cout<<"Bytes per Sector: "<<bytes_per_sectors<<endl;
	cout<<"RPM: "<<rpm<<endl;
	cout<<"Average Seek Time: "<<average_seek_time<<endl;
	cout<<"Initial Head Position: "<<initial_head_position<<endl;
	cout<<"Requests: ";
	for(auto ele: requests) cout<<ele<<" ";
	cout<<endl;
	
	cout<<endl;
	cout<<"Average Rotational Delay (in seconds): "<<findAverageRotationalDelay(rpm)<<endl;
	cout<<"Total Seek Time: "<<totalSeekTimeUsingCSCAN(number_of_cylinder,initial_head_position,requests)<<endl;
	
	return 0;
}
