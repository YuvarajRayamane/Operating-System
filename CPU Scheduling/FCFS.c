ccoad:
//FCFS :-First Come First Served


#include <stdio.h>
int main()
{
 int i,j,n,bt[100],wait[100],t[100];
 printf("Enter the number of process\n");
 scanf("%d",&n);
 printf("\n Enter burst times\n");
 for(i=0;i<n;i++)
 scanf("%d",&bt[i]);
 wait[0]=0,t[100]=0;
 float sum=0,sum1=0;
 for(j=1;j<=n;j++){
     wait[j]=wait[j-1]+bt[j-1];
     printf("\n Wait time for process %d is %d\n",j-1,wait[j-1]);
     sum=sum+wait[j-1];
    }
 printf("\n Average wait time is = %.2f",sum/n);
 printf("\n\n");
 for(j=1;j<=n;j++){
    t[j]=t[j-1]+bt[j-1];
     printf("\n turnaround time for process %d is %d\n",j,t[j]);
     sum1=sum1+t[j];
    }
    printf("\n Average turnaround time is = %.2f",sum1/n);
 return 0;
}
