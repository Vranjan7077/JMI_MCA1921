#include<iostream>
using namespace std;
class check
{
	private:
	    int n;
	public:
		check()
		{
			n=0;
		}
		void set(int x)
		{
			n=x;
		}
		void operator!()
		{
			if(n%2==0)
				cout<<endl<<"The number you have entered is : "<<"EVEN";
			else 
				cout<<endl<<"The number you have entered is : "<<"ODD";
		}
};
main()
{
	check number1;
	int temp;
	cout<<"Enter the Values : ";
	cin>>temp;
	number1.set(temp);
	!number1;
}
