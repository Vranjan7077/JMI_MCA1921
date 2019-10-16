#include<iostream>
#include<conio.h>
using namespace std;
class civil_time
{
	int hour,minute,c;
	public:
			civil_time()
			{
				hour=0;
				minute=0;
				c=5;
			}
			civil_time(int h,int m,int ch)
			{
				hour=h;	
				minute=m;
				c=ch;
			}
			void disp()
			{
				cout<<"\nTime in Civil format\n";
				if(c==1)
						cout<<"\nTime: "<<hour<<":"<<minute<<" p.m ";
				else if(c==0)
						cout<<"\nTime: "<<hour<<":"<<minute<<" a.m  ";
			}
};
class rail_time
{
	private:
	int hour,minute;
	public:
			void setdata();
			void disp()
			{
				cout<<"time: "<<hour<<":"<<minute;
			}
			operator civil_time()
			{
				if((hour>12))
							return(civil_time(hour-12,minute,1));
				else 
							return(civil_time(hour,minute,0));
			}
};

void rail_time::setdata()
{
		while(1)
		{
			cout<<"Enter hour: ";
			cin>>hour;
			cout<<"\nEnter minute:";
			cin>>minute;
			if(hour>24 || minute>60)
			{
					cout<<"\nInvalid entry...try again\n";
					continue;
			}
			else
					break;
		}
}
int main()
{
	rail_time r1;
	civil_time c1;
	r1.setdata();
	r1.disp();
	c1=r1;
	c1.disp();
}



