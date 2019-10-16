//jmi_p42-1.c on 26-08-18
//
//
//programe to compute frequency of character.
#include<stdio.h>
#include<stdlib.h>

int main()
{
  char *str;
	int freq[256] = {0}; // 256 char in ASCII
	int i;

  str = (char *)malloc(1024); // or   str = (char *)malloc(1024 * sizeof(char));
	printf("\nEnter string:\t");
	scanf("%[^\n]", str);

	for(i = 0 ; str[i] ; i++) freq[str[i]]++;// or for(i = 0 ; str[i] != '\0' ; i++)

	printf("\nFrequency of character is:\n\n");

	for( i = 0 ; i < 255 ; i++ )
	  if(freq[i]) // or if(freq[i] != 0)
	  	printf("\n'%c' occurs %d times.", i, freq[i] ) ;

	return 0;
}
