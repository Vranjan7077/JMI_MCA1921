#include<iostream>
using namespace std;

void test(float x,float y)
{
  //float (x);float (y);
 
 if(y!=0.0)
  {
   float r=x/y;
   cout<<"The Quotient: "<<r;
   }
 else
   throw(y);
  }

 int main()
  {
    int a,b,ch=0;
    try
     {
        
       do
        {
          cout<<"\nEnter the dividend: ";
          cin>>a;

        if (cin.fail())
            throw (a);
          
          cout<<"\nAnd the divisor: ";
            cin>>b;
       
          if (cin.fail())
            throw (b);

           test(a,b);

          cout<<"\nYou want to skip?\n Press 1 for YES 0 for NO: ";
          cin>>ch;

         }while(b!=0 || ch!=1);
       }

       catch(float i)
        {
   cout<<"You can't divide by zero!!!!"<<endl;
    }

   catch(int j)
    {
        cout<<"Incompatible Datatype"<<endl;
    }
   return 0;
  }

