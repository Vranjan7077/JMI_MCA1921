//jmi_p41.c on 01-10-18
//
//program to compute lenght of string
//

#include<stdio.h>
#include<string.h>

int string_lenght(char *str)
{
	int len, tab = 0;

	for( len = 0 ; *(str + len) ; len++ ) // or	for( len = 0 ; *(str + len) != '\0' ; len++ )
	{
	 if( *(str + len) ==  9)  // ASCII Code of Horizontal Tab is 9
	 	tab += 7;
	 }

	return len + tab;
}

int main()
{
	char str[100];

	printf("\nEnter string:\t");
	scanf("%[^\n]", str);

	printf("\nString lenght is %d.", string_lenght(str));

  return 0;
}
