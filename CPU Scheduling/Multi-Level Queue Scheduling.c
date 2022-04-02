ccoad:

#include <stdio.h>
#include <stdlib.h>

void FCFS(int burst_time[100],int initial_waiting_time,int n)
//n=process count
{
 float total_turnaround_time=0, total_waiting_time=0;
 printf("\n \tProcess\tBurst time\tWaiting time\tTurnaround time\n");
 for(int waiting_time,turnaround_time=initial_waiting_time,i=0;i<n;i++){
    turnaround_time+=burst_time[i];
    waiting_time=turnaround_time-burst_time[i];
    total_waiting_time+=waiting_time;
    total_turnaround_time+=turnaround_time;
    printf("\tP%d\t%d\t\t%d\t\t%d\n",i+1,burst_time[i],waiting_time,turnaround_time);
   }
 printf("\n Average waiting time = %.2f",total_waiting_time/n);
 printf("\n Average Turnaround time = %.2f",total_turnaround_time/n);
}

int main()
{
 int p1,p2;
 printf("\n Enter priority for Queue 1:");
 scanf("%d",&p1);
 printf("\n Enter priority for Queue 2:");
 scanf("%d",&p2);
 int nq1,nq2,i,t1=0,t2=0;//t1=turnaround time for queue 1, t2=turnaround time for q2, nq1=process count for queue 1, nq2= process count for queue 2;
 if(p1==p2){
   printf("\n Priority cannot be same");
   exit(1);
   }
 
 printf("\n Queue 1");
 printf("\n \t Enter the number of process:");
 scanf("%d",&nq1);
 int btq1[nq1];
 for(i=0;i<nq1;i++){
    printf("\n Enter the burst time for process %d:",i+1);
    scanf("%d",&btq1[i]);
    t1+=btq1[i];
    }

 printf("\n Queue 2:");
 printf("\n \t Enter the number of process :");
 scanf("%d",&nq2);
 int btq2[nq2];
 for(i=0;i<nq2;i++){
     printf("\n Enter the burst time for process %d:",i+nq1+1); 
     scanf("%d",&btq2[i]);
     t2+=btq2[i];
     }
 
if(p1<p2){
  printf("\nQueue 1:\n");
  FCFS(btq1,0,nq1);
  printf("\nQueue 2:\n");
  FCFS(btq2,t1,nq2);
  }
else{
  printf("\nQueue 2:\n");
  FCFS(btq2,0,nq2);
  printf("\nQueue 1:\n");
  FCFS(btq1,t2,nq1);
  }

 return 0;
}

