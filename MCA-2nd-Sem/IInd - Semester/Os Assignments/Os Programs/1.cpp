//Priority scheduling
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
	printf("Enter the total number of processes:");
	scanf("%d",&n);
	printf("\nEnter the burst time and the Priority:\n");
	for(i=0;i<n;i++)
	{
		printf("\nP[%d]\n",i+1);
		printf("The Burst Time:");
		scanf("%d",&bt[i]);
		printf("Priority:");
		scanf("%d",&pr[i]);
		p[i]=i+1;//contains process member
	}
	//Sorting burst time , priority and process number in ascending order using selection sort
	for(i=0;i<n;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(pr[j]<pr[pos])
			pos=j;
		}
		temp=pr[i];
		pr[i]=pr[pos];
		pr[pos]=temp;
		temp=bt[i];
		bt[i]=bt[pos];
		bt[pos]=temp;
		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;
	}
	wt[0]=0;//waiting for the first process which is zero
	//calculate waiting time
	for(i=1;i<n;i++)
	{
		wt[i]=0;
		for(j=0;j<i;j++)
		wt[i]+=bt[j];
		total+=wt[i];
	}
	avg_wt=total/n;//average waiting time
	total=0;
	printf("\n Process\t Burst time \tWaiting time \tTurn around time");
	for(i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
		total+=tat[i];
		printf("\nP[%d]\t\t %d\t\t %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
	}
	avg_wt=total/n;//average turn around time
	printf("\n\nAverage waiting time=%d",avg_wt);
	printf("\n\nAverage Turn around time=%d",avg_tat);
	return 0;
}

