//jmi_p29.c on 11-10-18
//
//program to check whether a string is palindrome or not.
//

#include<stdio.h>
#include<string.h>

int check_palindrome(char *str, int start, int end)
{
	if( start >= end )
	 return 1;
	else if( str[start] != str[end] )
   return 0;
  else
   check_palindrome(str, ++start, --end);
}

int main()
{
	int len, start, end, is_palindrome = 1;

	char str[100];

	printf("\nEnter string:\t");
	scanf("%[^\n]", str);

	len = strlen(str);

	is_palindrome = check_palindrome( str, 0, len - 1); // check_palindrome(string, start, end)

	if( is_palindrome)
	 printf("\nString is Palindrome.");
	else
	 printf("\nString is not Palindrome.");
	return 0;
}
