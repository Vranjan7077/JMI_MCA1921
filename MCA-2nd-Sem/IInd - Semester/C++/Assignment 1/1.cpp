#include<iostream>
using namespace std;

class largest 
{
	int n1,n2,n3;
	public:
		inline void largest1()
		{
			cout<<"Enter the numbers:";
			cin>>n1>>n2>>n3;
			if(n1>n2 && n1>n3)
				cout<<"Largest Number:"<<n1<<endl;
			else if(n2>n1 && n2>n3)
				cout<<"Largest Number:"<<n2<<endl;
			else
				cout<<"Largest Number:"<<n3<<endl;
		}
};

int main()
{
	largest l;
	l.largest1();
	return 0;
}

