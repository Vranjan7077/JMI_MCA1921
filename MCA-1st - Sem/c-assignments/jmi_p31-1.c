//jmi_p31-1.c
//
//programe to search an element using linear search
//
#include<stdio.h>

int main()
{
	int arr[100], n, i, key, is_found = 0;

	do{
 	   printf("\nEnter no of elements:\t");
	   scanf("%d", &n);

	   if( n < 1 ) printf("\nInvalid Input...!Try Again.");
	  }while( n < 1);
	printf("\nEnter %d elements:", n);

	for( i = 0; i < n; i++ )
	  printf("\n%d > ", i + 1),scanf("%d", &arr[i]);

	printf("\nElements are as follows:");
	for( i = 0; i < n; i++ )
		printf("\n%d > %d", i + 1, arr[i]);

	printf("\nEnter value to search:\t");
	scanf("%d", &key);

	for( i = 0 ; i < n ; i++ )
	{
	 if(arr[i] == key)
	 {
     is_found = 1;
	   break;
	 }
  }

	if( is_found )
   printf("\nElement(%d) found at index %d",key, i + 1);
  else
   printf("\nElement(%d) not found.", key);

	return 0;
}
