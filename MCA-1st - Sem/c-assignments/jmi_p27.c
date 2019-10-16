//jmi_p27.c on 29-09-18
//
//programe to show movements of disks of tower of hanoi
//
#include<stdio.h>
#include<assert.h>

void tower_of_hanoi(int n, char source, char destination, char temp)
{
	if(n == 1)
	{
		printf("\nMove disk %d %c to %c.", n, source, destination);
	  return ;
	}
	else
	{
		tower_of_hanoi(n - 1, source, temp, destination);           //t_o_h(n, s, d, t);
		printf("\nMove disk %d %c to %c.", n, source, destination);
		tower_of_hanoi(n - 1, temp, destination, source);           //t_o_h(n, s, d, t);
	}
}

int main()
{
	int n;

	do{
	   printf("\nEnter no of disks:\t");
	   scanf("%d", &n);

		 if( n < 1 ) printf("\nInvalid Input...! Try Again.");
	  }while( n < 1 );

	tower_of_hanoi(n, 'A', 'C', 'B');

	return 0;
}
