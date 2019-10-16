#include<iostream>
using namespace std;
class Complex
{
	private:
	       int real,imaginary;
	public:
		Complex()
		{
			real=imaginary=0;
		}
		Complex(int x)
		{
			real=imaginary=x;
		}
		Complex(int x, int y)
		{
			real=x;
			imaginary=y;
		}
		friend Complex add(Complex&,Complex&);
		friend void disp(Complex);
};
Complex add(Complex &a, Complex &b)
{
	Complex c;
	c.real=a.real+b.real;
	c.imaginary=a.imaginary+b.imaginary;
	return c;
}
void disp(Complex a)
{
	cout<<endl<<"Complex Number : "<<a.real;
	if(a.imaginary<0)
	{
		cout<<a.imaginary<<" i ";
	}
	else cout<<" + "<<a.imaginary<<" i ";
}
int main()
{
	Complex a(9,0),b(7,-5),c;
	disp(a);
	disp(b);
	c=add(a,b);
	disp(c);
}
