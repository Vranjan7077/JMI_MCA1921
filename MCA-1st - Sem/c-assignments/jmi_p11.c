//
//jmi_p11.c on 10-08-18
//
//Program to compute a frequency of a specified digit in a no.

#include<stdio.h>

int main()
{
  long int num, temp;
  short int key, rem, count = 0;

  printf("\nEnter a number:\t");
  scanf("%ld", &num);

  do{
      printf("\nEnter a key digit:\t");
      scanf("%hd", &key);

      if( key < 0 || key > 9 )
        printf("\nInvalid Input...! Try Again.");

    }while( key < 0 || key > 9 );

  temp = num;
  while(num)
  {
   rem = num % 10;
     if(rem == key) count++;
   num = num / 10;
  }
  if( count != 0 )
   printf("\n%hd occurs %hd times in %ld.\n", key, count, temp);
  else
   printf("\n%hd does't occur in %ld.\n", key, temp);

  return 0;
}
