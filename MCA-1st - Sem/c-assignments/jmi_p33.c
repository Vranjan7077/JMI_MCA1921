//jmi_p33.c on 17-08-18
//
//programe to find frequency of each element in array
//
#include<stdio.h>
int main()
{
	int arr[100], n, i , j, freq, flag = 0;
  do{
	   printf("\nEnter no of values:\t");
	   scanf("%d", &n);
		 if( n < 1 ) printf("\nInvalid Input...!Try Again.");
	 }while( n < 1 );

 	printf("\n\nEnter %d values:", n);

	for( i = 0; i < n; i++ ) //scanning values
	 printf("\n%d > ", i + 1),scanf("%d", &arr[i]);

	printf("\n\nValues are as follows:\n\n");

	for(i = 0; i < n; i++)//printing values.
		printf("\n%d > %d", i + 1, arr[i]);

	printf("\n\n");
	for(i = 0 ; i < n ; i++)
	{
	   for( j = 0 ; j < i ; j++) // checking whether element frequency has be computed or not
	  	 if(arr[j] == arr[i]) flag = 1;

     if(flag)// skip iteration if frequency has been computed
     {
      flag = 0;
      continue;
	   }

	   freq = 0;  // compute  frequency

	   for(j = i; j < n; j++)
	   {
	    if(arr[i] == arr[j])
	    {
	      freq++;
	    }
	   }
      printf("\nFrequency of %d is :\t %d.", arr[i], freq);
	 }
	return 0;
}
