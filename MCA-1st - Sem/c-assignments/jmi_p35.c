//jmi_p35.c on 30-09-18
//
//program to sort array elements using bubble sort
//
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, temp, i, j;

	do{
	   printf("\nEnter no of elements:\t");
   	 scanf("%d", &n);

		 if( n < 1 ) printf("\nInvalid Input...! Try Again.");
	  }while( n < 1 );

	int arr[n];

	printf("\nEnter %d elements:", n);

	for( i = 0 ; i < n ; i++ )    //scanning values
		printf("\n %d > ", i + 1), scanf("%d", &arr[i]);

	for(i = 0 ; i < n - 1 ; i++)  //sorting array
	{
	  for(j = 0 ; j < n - i - 1 ; j++)
	  {
		 if( arr[j] > arr[j+1] )
	   {
	    temp =  arr[j];
	    arr[j] = arr[j+1];
		  arr[j + 1] = temp;
	   }
	  }
	}

	printf("\nSorted elements are as :");
	for( i = 0 ; i < n ; i++ ) // print sorted array
	 printf("\n%d > %d ",i + 1 , arr[i]);

	return 0;
}
