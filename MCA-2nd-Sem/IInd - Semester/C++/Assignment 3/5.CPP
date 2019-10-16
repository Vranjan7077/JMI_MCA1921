#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
class string
{
char *str1;
public:
void setdata(char *s);
string operator+(string&);
int operator==(string &);
void disp()
{
puts(str1);
}
};
void string::setdata(char *s)
{
strcpy(str1,s);
}
string string::operator+(string &s)
{
string ob;
int i=0,j=0;
while(str1[i]!='\0')
i++;
str1[i]=' ';
while(s.str1[j]!='\0')
{
str1[i]=s.str1[j];
i++;
j++;
}
str1[i]='\0';
strcpy(ob.str1,str1);
return ob;
}
int string::operator==(string &s)
{
 if (strcmp(str1,s.str1)==0)
 return 0;
 else
 return 1;
 }

void main()
{
char *s1,*s2;
int a=2;
string ob1,ob2,ob3;
clrscr();
cout<<"enter any string: ";
cin>>s1;

ob1.setdata(s1);
cout<<"\nenter any other string:" ;
cin>>s2;
ob2.setdata(s2);
cout<<"\nfirst string: ";
ob1.disp();
cout<<"\nsecond string: ";
ob2.disp();
ob3=ob1+ob2;
cout<<"\nstring after concatenation: " ;
ob3.disp();
a=ob1==ob2;
if(a==0)
cout<<"\nboth strings are same";
else
cout<<"both string are not same";
getch();
}
