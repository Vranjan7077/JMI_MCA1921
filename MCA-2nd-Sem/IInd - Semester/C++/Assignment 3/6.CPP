#include<iostream>

#include<conio.h>
class distance
{
	float feet,inch;
	public:
			void setdata();
			void disp();
			operator float()
			{			
				float m;
				m=(feet*.3)+(inch*.025);
				return(m);
			}
};

void distance::setdata()
{
	cout<<"enter feet: ";
	cin>>feet;
	cout<<"\nenter inch: ";
	cin>>inch;
}

void distance::disp()
{
		cout<<"distance: "<<feet<<"feet"<<inch<<"inches";
}

int main()
{
	distance d;
	float met;
	d.setdata();
	d.disp();
	met=d;
	cout<<"\ndistance in meter: ";
	cout<<met;
	return 0;
}



