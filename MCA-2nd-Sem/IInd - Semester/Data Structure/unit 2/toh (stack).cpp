//
//
//programe to show movements of disks of tower of hanoi using stack
//
#include<iostream>
#include<stack>    // using STL
using namespace std;

class toh
{
	stack <int> s1;
	stack <char>s2, s2, s3, s4;
	char s, d, i;

public:
void towerOfHanoi(int n)
{
	s1.push(n); s2.push('A'); s3.push('B'); s4.push('C'); // s2 === source
  while(s1.empty() == false)                            // s3 === intermediate
	{                                                     // s4 === destination
		n = s1.top(); s= s2.top(); i = s3.top(); d = s4.top();
		s1.pop(); s2.pop(); s3.pop(); s4.pop();

		 if(n > 1)
		 {
			 s1.push(n-1), s2.push(i), s3.push(s), s4.push(d);
			 s1.push(1), s2.push(s), s3.push(i), s4.push(d);
			 s1.push(n-1), s2.push(s), s3.push(d), s4.push(i);
		 }
		 else
		   cout << endl << "Move disk "  << n << " from "<< s << " to " << d << ".";
	}
}
};

int main()
{
	int n;
	do{
	   cout << endl << "Enter no of disks : ";
	   cin >> n;
		 if(n < 1) cout << endl << "Invalid input...!";
	 }while(n < 1);

	toh t;
	t.towerOfHanoi(n);

	return 0;
}
