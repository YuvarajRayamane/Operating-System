#include <stdio.h>
#include <stdlib.h>

void worstfit(int a[],int p[],int n,int m)
{
int i,j,q=-1,t,f;
int id[n];
for(i=0;i<n;i++) id[i]=0;
for(i=0;i<m;i++)
{
q=-1; f=0;
for(j=0;j<n;j++)
{
if(a[j]-p[i]>q && id[j]==0)
{
q=a[j]-p[i];
t=j;
f=1;
}
}
if(f==0)
printf("%d\t%d\tNA\n",i+1,p[i]);
else
{
printf("%d\t%d\t%d\n",i+1,p[i],t+1);
id[t]=1;
}
}
}

void bestfit(int a[],int p[],int n,int m)
{
int i,j,q=-1,t,f;
int id[n];
for(i=0;i<n;i++) id[i]=0;
for(i=0;i<m;i++)
{

q=100000;f=0;
for(j=0;j<n;j++)
{
if((a[j]-p[i])<q && (a[j]-p[i])>0 && id[j]==0)
{
q=a[j]-p[i];
t=j;
f=1;
}
}
if(f==0)
printf("%d\t%d\tNA\n",i+1,p[i]);
else
{
printf("%d\t%d\t%d\n",i+1,p[i],t+1);
id[t]=1;
}
}
}

void firstfit(int a[],int p[],int n,int m)
{
int i,j,q=-1,t,f;
int id[n];
for(i=0;i<n;i++) id[i]=0;
for(i=0;i<m;i++)
{
f=0;
for(j=0;j<n;j++)
{
if(a[j]>=p[i] && id[j]==0)
{
t=j;
f=1;

break;
}
}
if( f==0)
printf("%d\t%d\tNA\n",i+1,p[i]);
else
{
printf("%d\t%d\t%d\n",i+1,p[i],t+1);
id[t]=1;
}
}
}

int main()
{
int n,m,i;
printf("Enter the Number of holes in Memory\n");
scanf("%d",&n);
int a[n];
printf("Enter the blocksize of Each Hole\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("Enter the Number of processes to which memory to be assigned\n");
scanf("%d",&m);
int p[m];
printf("Enter the Memorysize of Each process\n");
for(i=0;i<m;i++)
scanf("%d",&p[i]);
printf("\nWorstfit\nProcess no. Process size Hole no.\n");
worstfit(a,p,n,m);
printf("\nBestfit\nProcess no. Process size Hole no.\n");
bestfit(a,p,n,m);

printf("\nfirstfit\nProcess no. Process size Hole no.\n");
firstfit(a,p,n,m);
}



