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
	int flag;
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


// Algorithm for Round Robin scheduling

void RR(processes P[],int n){
	processes temp1[n],temp2[n];
	for(int i=0;i<n;i++){
		temp1[i]=P[i];
		temp1[i].response_time =-1;
	}

	// Sorting on the basis of arrival time
	arrival_sort(temp1,n);

	for(int i=0;i<n;i++){
		temp2[i] = temp1[i];
	}

	int quantum_time = 1;

	int sum_waiting=0, sum_turnaround=0, sum_response=0;
	printf("Quantum time as given it is 1 . \n\n");

	// Printing Gantt chart and calculating others
	printf("Gantt chart of CPU for these processes:  \n\n");
	int t,tcurr=0,pflag=0;
	for(int k=0; ; k++){
		if(k>n-1){
			k=0;
		}
		if(temp1[k].burst_time >0){
			printf("  %d  %s ",tcurr , temp1[k].name);
		}
		t=0;
		while(t<quantum_time && temp1[k].burst_time>0){
			t++;
			tcurr++;
			temp1[k].burst_time--;
		}
		if(temp1[k].burst_time <= 0 && temp1[k].flag !=1 ){
			temp1[k].waiting_time = tcurr - temp2[k].burst_time -temp1[k].arrival_time;
			temp1[k].turn_around_time = tcurr - temp1[k].arrival_time;
			pflag++;
			temp1[k].flag=1;
			sum_waiting += temp1[k].waiting_time;
			sum_turnaround += temp1[k].turn_around_time;
		}
		if(temp1[k].response_time == -1){
			temp1[k].response_time = tcurr -1 - temp1[k].arrival_time;
			sum_response +=temp1[k].response_time;
		}
		if(pflag==n){
			break;
		}
	}
	printf("  %d\n\n\n",tcurr );

	printf("Table showing info about the processes: \n\n");
	for(int i=0;i<n;i++){
		temp1[i].burst_time = temp2[i].burst_time;
	}
	print_table(temp1,n);

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
	fclose(fp);

	// SJF Algorithm
	printf("\n");
	RR(P,n);
	return 0;
}