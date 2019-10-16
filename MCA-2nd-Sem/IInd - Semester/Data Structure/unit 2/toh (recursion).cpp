//
//
//programe to show movements of disks of tower of hanoi
//
#include<iostream>
using namespace std;

void tower_of_hanoi(int n, char source, char destination, char temp)
{
	if(n == 1)
	{
		cout << endl << "Move disk no " << n << " from " << source << " to " << destination;
	  return ;
	}
	else
	{
		tower_of_hanoi(n - 1, source, temp, destination);           //t_o_h(n, s, d, t);
    cout << endl << "Move disk no " << n << " from " << source << " to " << destination;
		tower_of_hanoi(n - 1, temp, destination, source);           //t_o_h(n, s, d, t);
	}
}

int main()
{
	int n;
	do{
     cout << endl << "Enter no of disks : ";
		 cin >> n;

		 if( n < 1 ) cout << endl << "Invalid Input...! Try Again.";
	  }while( n < 1 );

	tower_of_hanoi(n, 'A', 'C', 'B');

	return 0;
}
