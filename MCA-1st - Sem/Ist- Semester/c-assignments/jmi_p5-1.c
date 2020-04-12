//
//jmi_p5-1.c on 09-08-18
//
//program to
#include <stdio.h>

int main()
{
	char name[30];

	int gross_sales, net_income;

	printf("Enter name of Employee :\t");
	scanf("%[^\n]", name);

	printf("\nEnter gross sales of %s :\t", name);
	scanf("%d", &gross_sales);

	net_income = 1000 + ( gross_sales * 10 / 100 );

	printf("\n*****************************");
	printf("\n*Name\t\tTotal Income*");
	printf("\n*****************************");

	printf("\n%s\t\t%d", name, net_income);

	return 0;
}
