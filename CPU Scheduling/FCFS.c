ccoad:
//FCFS :-First Come First Served


#include <stdio.h>
int main()
{
 int i,j,n,bt[100],wait[100],t[100];   //n=number process; bt=Burst time; wait=waiting time; t=turnaround time
 printf("Enter the number of process\n");
 scanf("%d",&n);
 printf("\n Enter burst times\n");
 for(i=0;i<n;i++)
 scanf("%d",&bt[i]);
 wait[0]=0,t[100]=0;
 float total_waiting_time=0,total_turnaround_time=0;       
 for(j=1;j<=n;j++){
     wait[j]=wait[j-1]+bt[j-1];
     printf("\n Wait time for process %d is %d\n",j-1,wait[j-1]);
     total_waiting_time = total_waiting_time + wait[j-1];
    }
 printf("\n Average wait time is = %.2f",total_waiting_time/n);
 printf("\n\n");
 for(j=1;j<=n;j++){
    t[j]=t[j-1]+bt[j-1];
     printf("\n turnaround time for process %d is %d\n",j,t[j]);
     total_turnaround_time = total_turnaround_time + t[j];
    }
    printf("\n Average turnaround time is = %.2f",total_turnaround_time/n);
 return 0;
}
