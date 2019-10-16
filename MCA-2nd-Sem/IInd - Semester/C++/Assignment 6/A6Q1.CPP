#include<iostream.h>
#include<stdexcept.h>
float Division(float nume, char deno)
{  int final;
   if (deno == 48)
   {   throw runtime_error("\nError: Divide by Zero");
   }
   else if (den >='a'&&den<='z')
   {   throw runtime_error("\nError: Divide by char");
   }
   else
   {  final=den-48;
      final=num/final;
   }
   return final;
}
void main()
{   clrscr();
    int nume;
    char deno;
    float result;
    cout<<"\nEnter numerator : ";
    nume=12.4 ;
    cout<<"\nEnter denominator : ";
    cin>>deno;
    try
    {   result=Division(nume,deno);
	cout<<"\nThe quotient is : "<<result;
    }
    catch (runtime_error& e)
    {   cout<<"\nException."<< e.what();
    }
    getch();
}

