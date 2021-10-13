#include<stdio.h>
#include<stdlib.h>

// Structure of process
typedef struct process{
	char name[5];
	int pid;
	int arrival_time;
	int priority;
	int share;
	int burst_time;
	int waiting_time;
	int response_time;
	int turn_around_time;
	int flag;
	int ticket_start;
	int ticket_end;
}processes;

// Sorting the process according to arrival time
void arrival_sort(processes temp[],int n){
	processes t;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++){
			if(temp[j].arrival_time >temp[j+1].arrival_time){
				t=temp[j];
				temp[j]=temp[j+1];
				temp[j+1]=t;
			}
		}
	}	
}

// Print Table
void print_table(processes p[], int n)
{
    int i;

    printf("---------+-----+---------------+------------+--------------+-----------------+----------------+\n");
    printf("| Pname  | PID | Arrival Time  | Burst Time | Waiting Time | Turnaround Time | Response Time  |\n");
    printf("---------+-----+---------------+------------+--------------+-----------------+----------------+\n");

    for(i=0; i<n; i++) {
        printf("|   %s   |  %d |       %d       |      %d     |       %d      |       %d         |       %d       |\n",
        		p[i].name,p[i].pid,p[i].arrival_time,p[i].burst_time,p[i].waiting_time,p[i].turn_around_time,p[i].response_time);
        printf("---------+-----+---------------+------------+--------------+-----------------+----------------+\n");
    }

}


// Implementation of FCFS Aldorithm
void lottery(processes P[],int n){
	processes temp[n],temp1[n];
	int total_ticket=0;
	int start=0;
	for(int i=0;i<n;i++){
		temp[i]=P[i];
		total_ticket+=temp[i].burst_time;
		temp[i].response_time=-1;
	}
	total_ticket+=temp[n-1].burst_time;

	// Sort according to arrival time
	arrival_sort(temp,n);

	// Now Sorting on the basis if priority
	processes t;
	for(int i=2;i<n;i++){
		for(int j=1;j<n-i+1;j++){
			if(temp[j].priority > temp[j+1].priority){
				t=temp[j];
				temp[j]=temp[j+1];
				temp[j+1]=t;
			}
		}
	}

	for(int i=0;i<n;i++){
		temp[i].ticket_start=start;
		start+=temp[i].burst_time+1;
		temp[i].ticket_end=start-1;
		temp1[i]=temp[i];
	}

	int tcurr=0;
	int sum_waiting=0, sum_turnaround=0, sum_response=0;
	int count=0;

	// Gantt Chart for lottery scheduling
	printf("\nGantt chart of CPU for these processes:  \n");
	printf("CPU taking time per second as follow\n\n");
	for(int i=0;;i++){
		int random= rand()%(total_ticket);
		// printf("%d\n",random );
		for(int j=0;j<n;j++){
			if(random>temp1[j].ticket_start && random<temp1[j].ticket_end){
				if(temp1[j].burst_time>0){
					temp1[j].burst_time--;
					if(temp[j].response_time==-1){
						temp[j].response_time=tcurr;
						sum_response+=temp[j].response_time;
					}
					tcurr++;
					printf("%s ",temp[j].name );
				}
				else if(temp1[j].burst_time==0 && temp[j].flag!=1){
					temp[j].flag=1;
					temp[j].turn_around_time= tcurr - temp[j].arrival_time;
					temp[j].waiting_time=temp[j].turn_around_time-temp[j].burst_time;
					sum_waiting+=temp[j].waiting_time;
					sum_turnaround+=temp[j].turn_around_time;
					count++;
				}
			}
		}
		if(count==n){
			break;
		}
	}
	printf("\n");
	printf("\n");
	printf("Table showing info about the processes: \n\n");
	print_table(temp,n);
	printf("\n");
	printf("\n");

	// Calculating Average waiting , Average turnaround and average response time
	float average_waiting_time, average_turnaround_time, average_response_time;
	average_waiting_time = (float)sum_waiting/n;
	average_turnaround_time = (float)sum_turnaround/n;
	average_response_time = (float)sum_response/n;

	printf("\n");
	printf("Average waiting time : %f\n",average_waiting_time );
	printf("Average turnaround time : %f\n",average_turnaround_time );
	printf("Average response time: %f\n",average_response_time );
	printf("\n");
	

}

int main(int args,char *argv[]){
	FILE *fp = fopen("process.dat","r");
	if(fp==NULL){
		printf("No such file exists.. Unable to open the file....\n");
		exit(-1);
	}
	// Taking number of process thorugh file
	int n;
	fscanf(fp,"%d",&n);	
	processes P[n];
	for(int i=0;i<n;i++){
		fscanf(fp,"%s",P[i].name);
		fscanf(fp,"%d",&P[i].pid);
		fscanf(fp,"%d",&P[i].arrival_time);
		fscanf(fp,"%d",&P[i].priority);
		fscanf(fp,"%d",&P[i].share);
		fscanf(fp,"%d",&P[i].burst_time);
		P[i].waiting_time = P[i].response_time = P[i].turn_around_time = 0;
	}

	// FIFS Algorithm
	lottery(P,n);

	fclose(fp);
	return 0;
}