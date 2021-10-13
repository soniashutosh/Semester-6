// Non preemptive approach

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

// Printing gantt chart
void print_gantt_chart(processes p[], int n)
{
    int i, j;
    // print top bar
    printf(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time; j++) printf("--");
        printf(" ");
    }
    printf("\n|");

    // printing process id in the middle
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time - 1; j++) printf(" ");
        printf("%s", p[i].name);
        for(j=0; j<p[i].burst_time - 1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    // printing bottom bar
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time; j++) printf("--");
        printf(" ");
    }
    printf("\n");

    // printing the time line
    int val =0;
    printf("0");
    for(i=1; i<=n; i++) {
    	val =val+ p[i-1].burst_time;
        for(j=0; j<p[i-1].burst_time; j++) printf("  ");
        // if(p[i].turn_around_time > 9) printf("\b"); // backspace : remove 1 space
        printf("%d", val);

    }
    printf("\n");

}


// Algorithm of Short Job First
void SJF(processes P[],int n){
	processes temp[n];
	for(int i=0;i<n;i++){
		temp[i]=P[i];
	}
	// Sorting on the basis of arrival time
	arrival_sort(temp,n);
	for(int i=0;i<n;i++){
		printf("%s  ",temp[i].name );
	}
	printf("\n");

	// Sorting on the basis of minimum job
	processes t;
	for(int i=2;i<n;i++){
		for(int j=1;j<n-i+1;j++){
			if(temp[j].burst_time > temp[j+1].burst_time){
				t = temp[j];
				temp[j] = temp[j+1];
				temp[j+1] = t;
			}
		}
	}

	for(int i=0;i<n;i++){
		printf("%s  ",temp[i].name );
	}

	int sum_waiting=0 , sum_turnaround=0, sum_response=0;

	//Calculating waiting, turnaround and response time
	sum_waiting = temp[0].waiting_time = 0;
	sum_turnaround = temp[0].turn_around_time = temp[0].burst_time - temp[0].arrival_time;
	sum_response = sum_waiting;

	for(int i=1;i<n;i++){
		temp[i].waiting_time = (temp[i-1].burst_time + temp[i-1].arrival_time+temp[i-1].waiting_time) - temp[i].arrival_time;
		temp[i].turn_around_time = temp[i].waiting_time+ temp[i].burst_time;
		temp[i].response_time = temp[i].waiting_time;
		sum_waiting += temp[i].waiting_time;
		sum_turnaround +=temp[i].turn_around_time;
		sum_response=sum_waiting;
	}

	// Printing table
	printf("Table showing info about the processes: \n");
	print_table(temp,n);

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

	// Printing CPU Gantt chart
	printf("Gantt chart of CPU for these processes:  \n");
	print_gantt_chart(temp,n);
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
	fclose(fp);

	// SJF Algorithm
	SJF(P,n);
	return 0;
}