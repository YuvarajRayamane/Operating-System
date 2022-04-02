ccoad:

# include <stdio.h>
int main()
{
 int i,j,n,bt[100],wait[100],b[100],m,k,t[100];
 printf("\n Enter number of process\n");
 scanf("%d",&n);
 printf("\n Enter burst times\n");
 for(i=0;i<n;i++){
     scanf("%d",&bt[i]);
     b[i]=i+1;
    }
 for(i=0;i<n-1;i++){
     for(j=0;j<n-1-i;j++){
         if(bt[j]>bt[j+1]){
            m=bt[j];
            bt[j]=bt[j+1];
            bt[j+1]=m;

            k=b[j];
            b[j]=b[j+1];
            b[j+1]=k;
           }
         }
      }
 wait[0]=0,t[0]=0;
 float sum=0,sum1=0;
 for(j=1;j<=n;j++){
    wait[j]=wait[j-1]+bt[j-1];
    printf("\n wait time for process %d is %d \n",b[j-1],wait[j-1]);
    sum=sum+wait[j-1];
    }
 printf("\n Average wait time is = %.2f",sum/n);
 printf("\n\n");
 for(j=1;j<=n;j++){
    t[j]=t[j-1]+bt[j-1];
    printf("\n turnaround time for process %d is %d \n",b[j-1],t[j]);
    sum1=sum1+t[j];
    }
 printf("\n Average turnaround time is = %.2f",sum1/n);
 return 0;
}
