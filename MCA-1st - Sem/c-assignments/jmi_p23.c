//
//jmi_p23 on 27-08-18
//
//programe to print pascal triangle using recursion

#include<stdio.h>
#include<assert.h>

long int fact(int n)
{
	if( n == 0)
	  return 1;
	else
	  return n * fact( n-1 );
}

long int nCr(int n, int r)
{
  return ( fact(n) / (fact(r) * fact(n - r)) );
}

int main()
{
  int lines, i, j;

  printf("\nEnter no of lines you want:\t");
  scanf("%d", &lines);

  for( i = 0 ; i < lines ; i++ )
  {
  	  for( j = 0 ; j <= lines - i ; j++ ) printf(" ");

  	  for(j = 0 ; j <= i ; j++ ) printf("%ld ", nCr(i, j) );

 	  printf("\n");
  }
 return 0;
}
