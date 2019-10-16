//
//jmi_p4-2.c on 09-08-18
//
//program to print decimal,octal & hexa-decdimal equiv. of a character.

#include<stdio.h>

int main()
{
 char ch;

 printf("\nEnter a character:\t");
 ch = getche();
                                      //You can also use type casting for these by :
 printf("\n\nDecimal = %d", ch);      // printf("\n\nDecimal = %d", (int) ch);
 printf("\nOctal = %o", ch);          // printf("\nOctal = %o", (int)ch);
 printf("\nHexa-deciaml = %X", ch);   // printf("\nOctal = %o", (int)ch);

 return 0;
}
