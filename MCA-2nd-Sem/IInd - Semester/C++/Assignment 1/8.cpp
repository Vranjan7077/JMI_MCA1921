#include<iostream>
#include<stdio.h>
using namespace std;
class Time
{
	private:
	    int hh,mm;
	    long tt;
	public:
		void gettime(int h, int m)
		{
			hh=h;
			mm=m;
		}
    friend Time sum(Time o1,Time o2);
	void display()
		{
			cout<<"\nThe Sum of two time Entered by User is:";
			cout<<""<<hh;
			cout<<":"<<mm<<endl;
		}
};
Time sum(Time o1,Time o2)
{
		Time o;
		o.hh=o1.hh+o2.hh;
		o.mm=o1.mm+o2.mm;
		if(o.mm>60)
		{
			o.hh=o.hh+(o.mm/60);
			o.mm=o.mm % 60;
		}
		return o;
	}
int main()
{
	int hh,mm,hh1,mm1;
	Time h1,h2,h;
	cout<<"\nEnter Hours:Minutes ";
	scanf("%d : %d",&hh,&mm);
	h1.gettime(hh,mm);
	cout<<"\nEnter Hours:Minutes ";
	scanf("%d : %d",&hh1,&mm1);
	h2.gettime(hh1,mm1);
	h=sum(h1,h2);
	h.display();
	return 0;
}
