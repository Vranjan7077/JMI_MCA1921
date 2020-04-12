//
//jmi_p3.c on 09-08-18
//
//program to compute diameter, area & circumference of a circle

#include<stdio.h>
#define PI 3.1415

int main()
{
 float r;
  
 printf("\nEnter radius :\t");
 scanf("%f", &r);
 
 printf("\n\nDiameter = %.2f", r * 2);
 printf("\nArea = %.2f", PI * r * r);
 printf("\nCricumference = %.2f",  2 * PI * r);
 
 return 0;
}
