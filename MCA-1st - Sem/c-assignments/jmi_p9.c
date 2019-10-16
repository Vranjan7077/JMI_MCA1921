//
//jmi_p9.c on 09-08-18
//
//program to check whether a number is a palindrome or not.

#include<stdio.h>

int main()
{
 long int num, reverse, temp, rem;

 printf("\nEnter a number:\t");
 scanf("%ld", &num);

 temp = num;
 reverse = 0;

 while(temp) // or while(temp != 0 )
 {
  rem = temp % 10;
  reverse = ( reverse * 10 ) + rem;
  temp = temp / 10;
 }

 if(num == reverse)
  printf("\n%ld is palindrome.\n", reverse);
 else
  printf("\n%ld is not palindrome.\n", reverse);

 return 0;
}
