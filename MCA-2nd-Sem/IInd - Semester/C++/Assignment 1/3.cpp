#include<iostream>
using namespace std;


class bankaccount
{
	char name[50];
	int acc_type
	long acc_no;
	float bal;
	public:
	 	void create();
	 	void withdraw(float);
	 	void deposit(float);
	 	void display();
	
};

void bankaccount :: create()			// for a Taking Basic Info
{
	cout<<"Enter your name:";
	cin>>name;
	cout<<endl<<"Enter Account Number:";
	cin>>acc_no;
	cout<<endl<<"Choose Your Account Type:"<<endl;
	cout<<"1-:Saving Account"<<endl<<"2-:Current Account"<<endl;
	cin>>acc_type;
	while(acc_type<1 || acc_type>2)
	{
		cout<<endl<<"Invalid Choice, Choose Again";
		cout<<endl<<"1-:Saving Account"<<endl<<"2-:Current Account: ";
		cin>>acc_type;
	}
   	cout<<endl<<"Enter Balance [Min. Rs.1000]: ";
	cin>>bal;
	 while(bal<1000)
	 {
		cout<<endl<<"Entered Balance is Less than [1000]... Enter Again [Min. Rs.1000] : ";
		cin>>bal;
	 }  
}
  
void bankaccount :: deposit(float amount)	// For deposite Amount
{
	bal=bal+amount;
	cout<<endl<<"Amount Succesfully Deposited.";
}

void bankaccount :: withdraw(float amount)
{
	if(amount<=bal)
   {
	bal=bal-amount;
	cout<<"Amount Succesfully Withdrawal";
    }
     else
     	cout<<"Insufficient balance in your account ";
}

void bankaccount :: display() 
{
	cout<<"Name:"<<name<<endl;
	cout<<"Account Number:"<<acc_no<<endl;
	if(acc_type==1)
		cout<<"Account Type : Saving Account"<<endl;
	else
		cout<<"Account Type : Current Account "<<endl;
		cout<<"Balance : "<<bal<<endl;
}



int main()
{

	int choice;
	float amount;
	bankaccount q;

	do
	{
		cout<<"1-: To Create account:"<<endl;
		cout<<"2-: To Deposit Amount:"<<endl;
		cout<<"3-: To Withdrawn:"<<endl;
		cout<<"4-: To Display Info:"<<endl;
		cout<<"0-: Exit"<<endl;
		cout<<endl<<"Choice : ";
		cin>>choice;
		switch(choice)
		{
			case 0:
				break;
			case 1:
				q.create();
				cout<<endl<<"Account Created.";
				break;
			case 2:
				cout<<endl<<"Enter Amount to be Deposited:";
				cin>>amount;
				q.deposit(amount);
				
				break;
			case 3:
				cout<<endl<<"Enter Amount to be Withdrawn : ";
				cin>>amount;
				q.withdraw(amount);
				break;
			case 4:
				q.display();
				break;				
		}
	}while(choice);
}




