//
//jmi_15.c on 13-08-18
//
//programe to compute exp(x)

#include<stdio.h>

int fact(int num)
{
	int i ,fact = 1;

	for( i = num; i != 0; i-- )fact = fact * i;
	return fact;
}

int xpowery(int x, int y)
{
	int i, prod = 1 ;

	for(i = 0 ; i < y; i++) prod = prod * x;
	return prod;
}

float __exp(int base, int range)
{
	int power = 0;
	int fct = 1;
	float sum = 0, temp = 0;

	while(power <= range)
	{
		sum +=  (float)xpowery(base, power) / fct;
	  power++;
    fct = fct * power;
	}
	return sum;
}

int main()
{
	int base, range;
  float res;

	printf("\nEnter base :\t");//base
	scanf("%d", &base);

	printf("\nEnter range:\t");// for more precision
	scanf("%d", &range);

	printf("\n\nResult = %f.", __exp(base, range));

  return 0;
}
