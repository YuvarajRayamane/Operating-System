ccoad:

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n,i,q,bt[100],wait,t,rem_bt[100];
   
    float sum=0,sum1=0;
    printf("Enter the number of process: ");
    scanf("%d", &n);
    printf("Enter the Burst time for each process\n");
    for (int i = 0; i < n; i++) {
        printf("\tP%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i]=bt[i];
    }
    printf("\tEnter time quantum: ");
    scanf("%d", &q);
     int remaining=n;
    printf("\nProcess\tBurst time\twaiting time\tturnaround time\n");
    
    for(wait,t=0,i=0;remaining!=0;i=(i+1)%n){
        if(rem_bt[i]>0 && rem_bt[i]<=q){
            t=t+rem_bt[i];
            rem_bt[i]=0;
            remaining--;
            wait=t-bt[i];
            sum=sum+wait;
            sum1=sum1+t;
            printf("\nP%d\t%d\t\t%d\t\t%d",i+1,bt[i],wait,t);
        }
      else if(rem_bt[i]>q){
          rem_bt[i]=rem_bt[i]-q;
          t=t+q;
      }
    }
    printf("\n Average waiting time = %f",sum/n);
    printf("\n Average turnaeround time =%f",sum1/n);
    return 0;
}
