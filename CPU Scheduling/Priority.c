ccoad:

#include <stdio.h>
int main()
{
    int i,j,n,t1,t2,t3,bt[100],wait[100],p[100],t[100],b[100];//t1,t2,t3=temporary variables
    printf("Enter the number of process\n");                //bt=burst time; p=priority; t=turnaround time;b[]=process numberP1,P2
    scanf("%d",&n);
    printf("\n Enter burst times and priority\n");
    for(i=0;i<n;i++){
        printf("\nP[%d]\n",i+1);
        printf("\n Burst time:");
        scanf("%d",&bt[i]);
        printf("\n Priority:");
        scanf("%d",&p[i]);
        b[i]=i+1;
    }
    
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(p[j]>p[j+1]){
                t1=p[j];
                p[j]=p[j+1];
                p[j+1]=t1;
                
                t2=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=t2;
                
                t3=b[j];
                b[j]=b[j+1];
                b[j+1]=t3;
            }
        }
    }
    wait[0]=0;
    t[0]=0;
    float total_waiting_time=0,total_turnaround_time=0;
    for(j=1;j<=n;j++){
        wait[j]=wait[j-1]+bt[j-1];
        total_waiting_time = total_waiting_time + wait[j-1];
    }
    printf("\n Process\t\tBurst time\t Waiting time\t\tTurnaround time\n");
    for(j=1;j<=n;j++){
        t[j]=t[j-1]+bt[j-1];
        total_turnaround_time = total_turnaround_time + t[j];
        printf("\n P[%d]\t\t\t%d\t\t\t%d\t\t\t%d",b[j-1],bt[j-1],wait[j-1],t[j]);
    }
    printf("\n Average wait time is = %.2f",total_waiting_time/n);
    printf("\n Average turnaround time is = %.2f",total_turnaround_time/n);    
    return 0;
}


