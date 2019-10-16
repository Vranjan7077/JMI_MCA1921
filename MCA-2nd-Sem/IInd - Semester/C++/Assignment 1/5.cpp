#include<iostream>
using namespace std;

class time
{
	int hh,mm,dd=0;
	long tt;
	public:
		void convert()
		{
			do
			{		
				if(mm>=60)
				{
					hh=hh+(mm/60);
					mm=mm%60;
				}
				if(hh>=24)
				{
					dd=dd+(hh/24);
					hh=hh%24;
				}
			}
			while(mm>=60 || hh>=24);
		}
	
		void gettime(int h, int m)
		{
			hh=h;
			mm=m;
		}
		void sum(time o2)
		{
			time t;
			hh=hh+o2.hh;
			mm=mm+o2.mm;
		}
		void display()
		{
			cout<<"\nThe Sum of two time Entered by User is(DD:HH:MM) ";
			cout<<"\n"<<dd<<" Days: "<<hh<<" Hours: "<<mm<<"Minutes";		
		}
};



int main()
{
	int hh1,mm1,hh2,mm2;
	time h1,h2;
	cout<<"\nEnter the time in HH:MM format:";
	cin>>hh1>>mm1;
	h1.gettime(hh1,mm1);
	cout<<"\nEnter Hours:Minutes ";
	cin>>hh2>>mm2;
	h2.gettime(hh2,mm2);
	h1.sum(h2);
	h1.convert();
	h1.display();		
	return 0;
}
