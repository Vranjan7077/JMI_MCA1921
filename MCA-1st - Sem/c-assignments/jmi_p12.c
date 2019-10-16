//
//jmi_p12.c on 12-08-18
//
//programe to determine whether given 3 sides can represent the sides of triangle

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int s1, s2, s3;
  char buffer[255];
	char choice = 'n';
  do{
	   printf("\nEnter three sides of a triangle(seperated by space):\t");
	   scanf("%d%d%d", &s1, &s2, &s3);

	   if( s1 < 1 || s2 < 1 || s3 < 1)
  	 {
	 	  printf("\nInvalid input....!");

		  printf("\nDo you want to Retry (Y/N) : ");
      fgets(buffer, sizeof(buffer), stdin); // clear input stream
		  scanf("%c", &choice);
		  if( choice != 'y' || choice != 'Y' )
		  return -1;
		 }

		}while(choice == 'y' || choice == 'Y');

	if(s1 + s2 > s3 && s2 + s3 > s1 && s3 + s1 > s2)
    printf("\n%d, %d, %d can represent the sides of triangle.", s1, s2, s3);
	else
	  printf("\n%d, %d, %d can't represent the sides of triangle.", s1, s2, s3);

	 return 0;
}
