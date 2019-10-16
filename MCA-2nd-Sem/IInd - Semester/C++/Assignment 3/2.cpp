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
		void operator--();
};
void check::operator--()
{
	int i,j; 
	int flag=1;
	for(i=2; i<=n/2; i++)
		if(n%i==0)
		{
			flag=0;
			break;
		}
		else 
			flag=1;
	if(flag==0)
		cout<<" NOT PRIME "<<endl;
	else 
		cout<<" PRIME "<<endl;
}
int main()
{
	check number1;
	int temp;
	cout<<"Enter the Value: ";
	cin>>temp;
	number1.set(temp);
	--number1;	
	return 0;
}
