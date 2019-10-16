//
//jmi_p20.c on  21-08-18
//
//programe to reverse a number
#include<stdio.h>

int main()
{
  int num, temp, reverse = 0, rem;

  printf("\nEnter a integer:\t");
  scanf("%d", &num);

  temp = num;

  while(temp) // or while(temp != 0)
  {
   rem = temp % 10;
   reverse = (reverse * 10) + rem;
   temp = temp / 10;
  }
 printf("\nReverse of %d is %d.", num, reverse);

 return 0;
}
