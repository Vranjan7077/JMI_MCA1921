#include<iostream>
#include<conio.h>
using namespace std;
class complex
{
        private:
           int r,i;
        public:
    void getdata()// getting the values of the complex part and the imaginary part
    {
         cout<<"\nEnter the complex number \n";
         cout<<"\nReal part :";
         cin>>r;
         cout<<"\nImaginary part :";
         cin>>i;
    }
    complex sum(complex c1,complex c2)//solving the both imaginary and the complex part using the object as a arguments.
    {
         r=c1.r+c2.r;
         i=c1.i+c2.i;
    }
   void show()// showing the result after solving the imaginary and the complex part
    {
         cout<<r<<" + "<<i<<" i";
         cout<<"\n";
    }
};
int main()
{
 complex t,a,b;
 a.getdata();
 a.show();
 b.getdata();
 b.show();
 t.sum(a,b);
 cout<<"After adding:\n";
 t.show();
 getch();
}
