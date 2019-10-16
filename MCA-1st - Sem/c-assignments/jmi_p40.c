//jmi_p40.c on 07-08-18
//
//program to compare two string
//

#include<stdio.h>

int compare_string(char *str1, char *str2)
{
   int i , j;

   for(i = 0, j = 0; *(str1 + i) != '\0' ||  *(str2 + j) != '\0'; i++, j++)
   {
		if(str1[i] != str2[j])
	     return 0;
   }

   return 1;
}

int main()
{
	int i, j, is_same;
  char buffer[255];
	char str1[100], str2[100];

	printf("\nEnter string 1:\t");
  scanf("%[^\n]", str1);
	printf("\nEnter string 2:\t");
  fgets( buffer, sizeof(buffer), stdin );  //clearing input stream.
  scanf("%[^\n]", str2);

	is_same = compare_string(str1, str2);

	if(is_same)
   	 printf("\nString are same.");
	else
	 printf("\nString are not same.");

	return 0;
}
