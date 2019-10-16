//
//jmi_p30-1.c on 09-10-18
//
//programe to ...

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int no_of_salesperson, i, j;

	int count_below_12h = 0, count_12h = 0, count_13h = 0, count_14h = 0, count_15h = 0, count_16h = 0, count_17h = 0, count_18h = 0, count_19h = 0, count_20h_and_above = 0;

	printf("\nEnter no of employee :\t");
	scanf("%d", &no_of_salesperson);

  int gross_sales[no_of_salesperson], net_salary[no_of_salesperson];

	for( i = 0 ; i < no_of_salesperson ; i++ )
	{
		printf("\nEnter gross sales of employee %d :", i + 1 );
		scanf("%d", &gross_sales[i]);

	   net_salary[i] = 1000 +  ( gross_sales[i] * 9 ) / 100;

     if(net_salary[i] < 1200) count_below_12h++;
	   else if( net_salary[i] >= 1200 && net_salary[i] <= 1299 ) count_12h++;
     else if( net_salary[i] >= 1300 && net_salary[i] <= 1399 ) count_13h++;
     else if( net_salary[i] >= 1400 && net_salary[i] <= 1499 ) count_14h++;
     else if( net_salary[i] >= 1500 && net_salary[i] <= 1599 ) count_15h++;
     else if( net_salary[i] >= 1600 && net_salary[i] <= 1699 ) count_16h++;
     else if( net_salary[i] >= 1700 && net_salary[i] <= 1799 ) count_17h++;
     else if( net_salary[i] >= 1800 && net_salary[i] <= 1899 ) count_18h++;
     else if( net_salary[i] >= 1900 && net_salary[i] <= 1999 ) count_19h++;
     else if( net_salary[i] >= 2000 )count_20h_and_above++;
	}

	for( i = 0 ; i < no_of_salesperson ; i++ )
		printf("\nSalary of salesman %d is %d.", i + 1, net_salary[i] );

	printf("\n\n");
	printf("\nTotal no of salespersons who's salary is below 1200  is %d.", count_below_12h);
	printf("\nTotal no of salespersons who's salary is from 1200 - 1299 is %d.", count_12h);
	printf("\nTotal no of salespersons who's salary is from 1300 - 1399 is %d.", count_13h);
	printf("\nTotal no of salespersons who's salary is from 1400 - 1499 is %d.", count_14h);
	printf("\nTotal no of salespersons who's salary is from 1500 - 1599 is %d.", count_15h);
	printf("\nTotal no of salespersons who's salary is from 1600 - 1699 is %d.", count_16h);
	printf("\nTotal no of salespersons who's salary is from 1700 - 1799 is %d.", count_17h);
	printf("\nTotal no of salespersons who's salary is from 1800 - 1899 is %d.", count_18h);
	printf("\nTotal no of salespersons who's salary is from 1900 - 1999 is %d.", count_19h);
	printf("\nTotal no of salespersons who's salary is from above  1999 is %d.", count_20h_and_above++);

  return 0;
}
