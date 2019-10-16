// A bank gives 4% interest on current account and 6% interest on savings account. An additional 3% interest
//is provided for savings duration of 5 years and above. Using dynamic initilazation of constructr write a 
//banking program using C++

#include<iostream>
using namespace std;
class Bank
{
	private:
	    char name[20],id[20];
	    float amount,extra;
	    int time,type;
	public:
		Bank()
		{
			cout<<"Enter name : ";
			gets(name);
			cout<<endl<<"Enter Account Number : ";
			gets(id);
			cout<<endl<<"1. Saving \n2. Current \nAccount Type : ";
			cin>>type;
			cout<<endl<<"Enter Amount : ";
			cin>>amount;
			cout<<endl<<"Enter Time (in Years) : ";
			cin>>time;
			extra=0;				
		}
		float calculateExtra()
		{
			if(type==1)
			{
				extra=amount*0.06;//here 6% calculation on the savings account
			}
			else if(type==2)
			{
				extra=amount*0.04;//here 4% calculation on the current account
			}
			if(time>=5)
			{
				extra=extra+(amount*0.03); //here 3% interest for savings above the 5 yrs.	
			}
		}
		void display()
		{
			cout<<endl<<"Name\t\t : "<<name;	
			cout<<endl<<"Account Number\t : "<<id;
			cout<<endl<<"Amount\t\t : "<<amount;
			cout<<endl<<"Extra amount\t : "<<extra;
			cout<<endl<<"Total\t\t : "<<extra+amount;
		}
};

int main()
{
	Bank b1;
	b1.calculateExtra();
	b1.display();
	return 0;
}
