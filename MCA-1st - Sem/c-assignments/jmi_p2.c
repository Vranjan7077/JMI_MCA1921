//
//jmi_p2.c on 09-18-18
//
//program to compute sum, average, product, smallest & greatest among 3 given numbers

#include<stdio.h>

int main()
{
 int num1, num2, num3;
 int result;
 
 printf("\nEnter a number:\t");
 scanf("%d", &num1);

 printf("\nEnter a number:\t");
 scanf("%d", &num2);

 printf("\nEnter a number:\t");
 scanf("%d", &num3);

 printf("\nSum ( %d + %d + %d ) = %d\n", num1, num2, num3, (num1 + num2 + num3));

 printf("\nProduct ( %d * %d * %d ) = %d\n", num1, num2, num3, (num1 * num2 * num3));

 printf("\nAverage ( %d + %d + %d ) / 3  = %.2f\n", num1, num2, num3, (float)(num1 + num2 + num3) / 3);

 if(num1 > num2)
   if(num1 > num3)
    result = num1;
   else
    result = num3;
 else if(num2 > num3)
    result = num2;
   else
    result = num3;
       
 printf("\nLargest ( %d , %d , %d ) = %d\n", num1, num2, num3, result);
 
 if(num1 < num2)
   if(num1 < num3)
    result = num1;
   else
    result = num3;
 else if(num2 < num3)
    result = num2;
   else
    result = num3;
       
 printf("\nSmallest ( %d , %d , %d ) = %d\n", num1, num2, num3, result);
 
 return 0;
}
