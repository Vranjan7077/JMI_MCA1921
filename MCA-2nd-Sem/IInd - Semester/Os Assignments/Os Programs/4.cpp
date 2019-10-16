//FCFS scheduling
#include<stdio.h>
#include<iostream>
using namespace std;
void find_Waiting_time(int processes[],int n,int bt[],int wt[])
{
	wt[0]=0;
	for(int i=1;i<n;i++)
	wt[i]=bt[i-1]+wt[i-1];
}
void find_turnaround_time(int processes[],int n,int bt[],int wt[],int tat[])
{
	for(int i=1;i<n;i++)
	tat[i]=bt[i]+wt[i];
}
void find_avg_time(int processes[],int n,int bt[])
{
	int wt[n],tat[n],total_wt=0,total_tat=0;
	find_Waiting_time(processes,n,bt,wt);
	find_turnaround_time(processes,n,bt,wt,tat);
	cout<<"-------------------------------------------------------------------\n";
	cout<<" Processes "<<"| Burst time "<<"| Waiting time "<<"| Turn around time \n";
	cout<<"-------------------------------------------------------------------\n";
	for(int i=1;i<n;i++)
	{
		total_wt=total_wt+wt[i];
		total_tat=total_tat+tat[i];
		cout<<" "<<i+1<<"\t\t"<<bt[i]<<"\t "<<wt[i]<<"\t\t "<<tat[i]<<endl;
	}
	cout<<"-------------------------------------------------------------------\n";
	cout<<"\nAverage waiting time = "<<(float)total_wt/(float)n<<endl;
	cout<<"\nAverage turn around time = "<<(float)total_tat/(float)n<<endl;
}
int main()
{
	int processes[]={1,2,3};
	int n=sizeof processes;
	int burst_time[]={10,5,8};
	find_avg_time(processes,n,burst_time);
	return 0;
}
