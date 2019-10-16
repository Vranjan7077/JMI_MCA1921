#include<iostream>
using namespace std;
class student
{
	char name[25];	
	int rollno;
	float mark1,mark2,mark3,total,average;
	public:
		void getdata()
		{
			cout<<"\nEnter Roll no:";
			cin>>rollno;
			cout<<"\nEnter Name:";
			cin>>name;
			cout<<"\nEnter Marks in Three Subjects:";
			cin>>mark1>>mark2>>mark3;
			total=mark1+mark2+mark3;
			average=total/3.0;
		}
	
		void displaydata()
		{
		cout<<"\nRoll no:"<<rollno;
		cout<<rollno;
		cout<<"\nName:"<<name;
		cout<<"\n Marks in Subject 1:";
		cout<<mark1;
		cout<<"\n Marks in Subject 2:";
		cout<<mark2;
		cout<<"\n Marks in Subject 3:";
		cout<<mark3;
		cout<<"\nTotal marks:"<<total;
		cout<<"\nAverage:"<<average<<"\n \n";

	}
};

	int main()
{

	student s[20];
	int n,i;
	cout<<"\nEnter no.of Students";
	cin>>n;
	for(i=0;i<n;i++)
	{
		s[i].getdata();
		
	}
	for(i=0;i<n;i++)
	{
		s[i].displaydata();
		
	}
	return 0;
	
}
