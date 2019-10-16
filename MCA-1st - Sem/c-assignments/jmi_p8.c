//
//jmi_p8.c on 09-08-18
//
//program to print a pattern.......

#include<stdio.h>

int main()
{
 int i, j, lines;

 printf("\nEnter no of lines you want:\t");
 scanf("%d", &lines);

 for(i = 1; i <= lines; i++)
 {
    for(j = i; j <= i * 3; j = j + i)
      printf("%d\t", j);

  printf("\n");
 }
 return 0;
}
