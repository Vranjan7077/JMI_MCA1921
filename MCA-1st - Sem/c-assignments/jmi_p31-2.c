//jmi_p31-2.c
//
//programe to search an element using linear search
//
#include<stdio.h>

int main()
{
	int arr[100], n, i, key, flag = 0;

	do{
 	   printf("\nEnter no of elements:\t");
	   scanf("%d", &n);

	   if( n < 1 ) printf("\nInvalid Input...!Try Again.");
	  }while( n < 1);
	printf("\nEnter %d elements:", n);

	for(i = 0; i < n; i++)
	  printf("\n%d > ", i + 1),scanf("%d", &arr[i]);

	printf("\nElements are as follows:");
	for(i = 0; i < n; i++)
		printf("\n%d > %d", i + 1, arr[i]);

	printf("\nEnter value to search:\t");
	scanf("%d", &key);

	for(i = 0 ; i < n ; i++)
	{
	 if(arr[i] == key)
	 {
	   if(!flag)
	   {
	    printf("\nElement(%d) found at index %d",key, i + 1);
        flag = 1;
	    continue;  // as flag is now set so we don't want to print its index again.
	   }
	   if(flag)
	 	  printf(", %d", i + 1);
	 }
  }
	printf(".");

	if(i > n)
  	 printf("\nElement not found.");

	return 0;
}
