//
//jmi_p24.c on 25-08-18
//
//programe to compute average of n-array floats by using recursion

#include<stdio.h>

float avg(int n, int count)
{
	static int sum = 0, i = 0
  float arr[15];

	if(!count)
	{
      float average = (float)sum / n ;
	    return average;
	}
	else
	{
		printf("\nEnter element %d : \t", i + 1);
		scanf("%f", &arr[i]);

		sum = sum + arr[i++];
        avg(n, --count);
 	}
}

int main()
{
   int n;
   do{
      printf("\nEnter no. of elements :\t");
      scanf("%d", &n);

      if( n < 1 ) printf("\nInvalid Input...!Try Again.");

     }while( n < 1 );
   printf("\nAverage is :\t%.2f", avg(n , n) );

   return 0;
}
