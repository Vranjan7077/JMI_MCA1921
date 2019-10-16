//jmi_p42-2.c on 17-08-18
//
//program to find frequency of each character in string
//
#include<stdio.h>
#include<string.h>

int main()
{
	int  freq, flag = 0, len, i, j;
	char str[100];

	printf("\nEnter string:\t");
  scanf("%[^\n]", str);
	len = strlen(str);

	for(i = 0 ; i < len ; i++)
	{
	   for( j = 0 ; j < i ; j++) // checking whether element frequency has be computed or not
	   {
	 	  if(str[j] == str[i])
		    flag = 1;
	   }

     if(flag)            // skip iteration if frequency has been computed
     {
      flag = 0;
      continue;
	   }

	 freq = 0;  // compute  frequency
	 for(j = i; j < len; j++)
	   if(str[i] == str[j]) freq++;

   printf("\nFrequency of \'%c\' is :\t%d.", str[i], freq);
	}
	return 0;
}
