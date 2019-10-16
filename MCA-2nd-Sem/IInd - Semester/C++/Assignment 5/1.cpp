#include<iostream>
using namespace std;
class least
{
   int a,b,c;
   public:
    least(int a,int b,int c)
      {
         this->a=a;
         this->b=b;
         this->c=c;
       }
   void putdata()
     {
       cout<<"\nSubject1= "<<a<<"\nSubject2= "<<b<<"\nSubject3= "<<c<<endl;
       int x=a<b?(a<c?a:c):(b<c?b:c);
       cout<<"The least of the three subject marks is: "<<x<<endl;
        }
    };

int main()
{
   int a,b,c;
   cout<<"\nEnter the marks of 3 subject: "<<endl;
   cout<<"Subject 1: ";cin>>a;
   cout<<"Subject 2: ";cin>>b;
   cout<<"Subject 3: ";cin>>c;
   least D(a,b,c);
   D.putdata();
   return 0;
}
