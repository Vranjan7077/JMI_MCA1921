/*class distance consisits of length inn feet and inches. Class distance contains
 I) one default constructor
 II) one parametrized constructor
 III) function getdata() to take the value of feet and inches.function show() to display.
 a)overload<operator to compare the two distances
 b) overload += operator in the diatance class.*/

#include<iostream>
using namespace std;
class distance1
{
	int feet,inch;
	public:
	distance1 operator+=(distance1 d)
	{
		distance1 temp;
		temp.feet=feet+d.feet;
		temp.inch=inch+d.inch;
		return(temp);
	}
		distance1()
		{
			feet=0;
			inch=0;
		}

		distance1(int f,int i)
		{
			feet=f;
			inch=i;
			if(inch>12)
			{
				feet=feet+inch/12;
				inch=inch%12;
 			}

		}
		void getdata();
		void show();
	
		bool operator<(distance1);
		
};

void distance1::getdata()
{
	cout<<"enter length in feet: ";
	cin>>feet;
	cout<<"enter length in inches: ";
	cin>>inch;
	if(inch>12)
	{
		feet=feet+inch/12;
		inch=inch%12;
 	}
}


bool distance1::operator<(distance1 d)
{
	if(feet<d.feet ||(feet==d.feet && inch<d.inch))
		return true;
	else
		return false;
}

void distance1::show()
{
	cout<<feet<<"feet "<<inch<<"inches\n";
}


int main()
{
	distance1 d1,d2,d3;
	d1.getdata();
	d2.getdata();
	cout<<"first distance1: "<<endl;
	d1.show();
	cout<<"second distance1: "<<endl;
	d2.show();
	if(d1<d2==true)
	{
		cout<<"after compairing,greater distance1 is: "<<endl;
		d2.show();
	}
	else
		d1.show();
	d3=d1+=d2;
	d3.show();
	return 0;
}


