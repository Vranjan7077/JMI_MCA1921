//
//jmi_p14.c on 20-08-18
//
//program to find all prime divisors of number
//
// Use cmd to Run from terminal 'gcc jmi_p14.c -lm'
//Note: Read article for more info. if u want to run this program from linux Terminal
// https://www.includehelp.com/c-programming-questions/compiling-program-with-math-library-linux.aspx

#include<stdio.h>
#include<math.h>
#include<limits.h>


void check_prime(int num)
{
	int i, is_prime = 1;

	for( i = 2; i <= sqrt(num) ; i++ )
	{
		if( num % i == 0 )
		{
		 is_prime = 0;
		 break;
    }
	}

	if(is_prime) printf("%d\t", num);
}

int main()
{
	int num, i = 1;

  do{
	    printf("\nEnter a positive Non-Zero integer( HINT : 1 < N < %d ):\t", INT_MAX);
	    scanf("%d", &num);

	    if( num < 1 || num > INT_MAX )
 	    printf("\nInvalid input...! Try Again");
    }while( num < 1 || num > INT_MAX );

	printf("\nPrime divisors of %d are:\t", num);

	for(i = 2; i <= num; i++)
	  if(num % i == 0) check_prime(i);

   return 0;
}
