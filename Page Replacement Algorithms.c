#include<stdio.h>
#include<stdlib.h>
int n,nf,i,j,k;
int in[100],p[100];
int hit=0;
int fault=0;
void getdata()
{
    printf("\nEnter length of page reference sequence:");
    scanf("%d",&n);
    printf("\nEnter the page reference sequence:");
    for(i=0; i<n; i++)
        scanf("%d",&in[i]);
    printf("\nEnter no of frames:");
    scanf("%d",&nf);
}
void initialize()
{
    fault=0;
    for(i=0;i<nf;i++)
    p[i]=9999;
}
int ishit(int item)
{
    hit=0;
    for(j=0;j<nf;j++)
    {
        if(p[j]==item)
        {
            hit=1;
            break;
        }
    }
    return hit;
}
int getindex(int item)
{
    int index1;
    for(k=0;k<nf;k++)
    {
        if(p[k]==item)
        {
            index1=k;
            break;
        }
    }
    return index1;
}
void display()
{
    for(k=0;k<nf;k++)
    {
        if(p[k]!=9999)
            printf(" %d",p[k]);
    }
}
void displayfault()
{
    printf("\nTotal no of page faults:%d\n",fault);
}

void fifo()
{
    initialize();
    printf("First in First out");
    for(i=0;i<n;i++)
    {
        printf("\nFor page %d:",in[i]);
        if(ishit(in[i])==0)
        {
            for(k=0;k<nf-1;k++)
                p[k]=p[k+1];
            
            p[k]=in[i];
            fault++;
            display();
        }
        else
        printf("No faults");
    }
    displayfault();
}
void lru()
{
    initialize();
    printf("Least Recently Used");
    int least[50];
    for(i=0; i<n; i++)
    {
 
        printf("\nFor page %d :",in[i]);
 
        if(ishit(in[i])==0)
        {
            for(j=0;j<nf;j++)
            {
                int pg=p[j];
                int found=0;
                for(k=i-1;k>=0;k--)
                {
                    if(pg==in[k])
                    {
                        least[j]=k;
                        found=1;
                        break;
                    }
                    else 
                        found=0;
                }
            }
            int min=9999,repindex;
            for(j=0;j<nf;j++)
            {
                if(least[j]<min)
                {
                    min=least[j];
                    repindex=j;
                }
            }
            p[repindex]=in[i];
            fault++;
            display();
            
        }
        else
        printf("No page faults");
    }
    displayfault();
}
void optimal()
{
    initialize();
    printf("Optimal");
    int near[50];
    for(i=0;i<n;i++)
    {
        printf("\nFor page %d :",in[i]);
        if(ishit(in[i])==0)
        {
            for(j=0;j<nf;j++)
            {
                int pg=p[j];
                int found=0;
                for(k=i;k<n;k++)
                {
                    if(pg==in[k])
                    {
                        near[j]=k;
                        found=1;
                        break;
                    }
                    else
                    found=0;
                }
                if(!found)
                    near[j]=9999;
            }
            int max=-9999,repindex;
            for(j=0;j<nf;j++)
            {
                if(near[j]>max)
                {
                    max=near[j];
                    repindex=j;
                }
            }
            p[repindex]=in[i];
            fault++;
            display();
        }
        else
        printf("No page fault");
    }
    displayfault();
}
int main()
{
    int c;
    while(1)
    {
        printf("____________________________\nEnter the choice:\n1.Enter data\n2.FIFO\n3.LRU\n4.Optimal\n5.Exit\n____________________________\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:getdata();
                    break;
            case 2:fifo();
                    break;
            case 3:lru();
                    break;
            case 4:optimal();
                    break;
            default:return 0;
                    break;
        }
        
    }
    return 0;
}

