//
//jmi_p39.c on 11-11-18
//
//programe to find maximum element using recursion

#include<stdio.h>

int max_element(int *arr, int count , int max )
{
	static int i = 0;

	if( !count )
		return max;
	else
	{
	  if( arr[i] > max)
		  max = arr[i];
	 i++;
	 max_element(arr, --count, max);
	}
}

int main()
{

	do{
	   printf("\nEnter no of elements :\t");
		 int n, max, i;
	   scanf("%d", &n);

     if( n  < 1 ) printf("\nInvalid Input...! Try Again.");
		}while( n < 1 );

  int arr[n];

	for( i = 0 ; i < n ; i++ )
	{
		printf("%d > ", i + 1 );
		scanf("%d", arr + i);
	}

	printf("\nArray elements are :\n");

	for( i = 0 ; i < n ; i++)
		printf("\n%d > %d ",i + 1 , arr[i]);

	printf("\n\n");

	max = max_element(arr, n, arr[0]);

	printf("\nMaximum element is : %d", max);

	return 0;
}
