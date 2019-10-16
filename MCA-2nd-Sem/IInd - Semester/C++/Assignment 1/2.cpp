#include<iostream>
using namespace std;
long hms_to_secs(int,int,int);
int main()
{
	int sec,min,hour;
	long allsec;
	cout<<"Enter the time in HH:MM:SS format:"<<endl;
	cout<<"HH:MM:SS:";
	cin>>hour>>min>>sec;
	allsec=hms_to_secs(hour,min,sec);
	cout<<"The time calculated in seconds:"<<allsec<<endl;
	return 0;
}


long hms_to_secs(int h,int m,int s)
{
	return (((h*60*60)+(m*60)+(s)));
}


