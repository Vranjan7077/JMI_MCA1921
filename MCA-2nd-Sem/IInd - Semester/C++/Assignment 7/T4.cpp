#include<iostream>
#include<math.h>
using namespace std;
template<class t,class s>
void cal(s a,t b)
{
	float result=0;
	result=pow(a,b);
	cout<<result;
}
int main()
{
	int b=2;
	float a=2.5;
	cal(a,b);
	return 0;
}
