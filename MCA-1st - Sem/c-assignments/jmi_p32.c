//jmi_p32.c on 20-08-18
//
//programe to search element using binary search
//

#include<stdio.h>

int main()
{
	int low, high, mid, n, i, item;
	int arr[100];
	do{
	    printf("\nEnter no of elements:\t");
	    scanf("%d", &n);

			if( n < 1 ) printf("\nInvalid Input...! Try Again.");
		}while(n < 1);

	printf("\nEnter %d elements:\n", n);

	for(i = 0 ; i < n ; i++)
		printf("\n%d > ", i + 1), scanf("%d", &arr[i]);

	printf("\nEnter element to found :\t");
	scanf("%d", &item);

	low = 0;
	high = n - 1;

	while(low <= high)
	{
 	 mid = ( low + high ) / 2;
   if(item > arr[mid])
		low = mid + 1;
	 else if(item < arr[mid])
		high = mid - 1;
   else
	 {
		printf("Search sucessful.");
		return 0;
	 }
	}
	printf("\nSearch unsuccessful...!");
	return 0;
}
