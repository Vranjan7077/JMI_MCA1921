//jmi_p38.c on 23-10-18
//
//program to generate circular matrix
//

#include<stdio.h>

int main()
{
	int order, first_row, first_col, last_row, last_col, i, j;
	int arr[50][50], num = 1;

  do{
	   printf("\nEnter the order of matrix(n):\t");
  	 scanf("%d", &order);

		 if( order < 1 ) printf("\nInvalid Input...! Try Again.");
	 }while( order < 1 );

	first_row = 0;
	first_col = 0;

	last_row = order - 1;
	last_col = order - 1;

	while( ( first_row <= last_col ) && ( first_col <= last_col ) )
	{
     for( i = first_col ; i <=  last_col ; i++ )
	    arr[first_row][i] = num++; //printing first row

   first_row++;

     for( i = first_row ; i <=  last_row ; i++ )
  	  arr[i][last_col] = num++;  //printing last col

   last_col--;

     for( i = last_col ; i >=  first_col ; i-- )
  	  arr[last_row][i]  = num++;//printing last row

	 last_row--;

     for( i = last_row ; i >=  first_row ; i-- )
  	  arr[i][first_col] = num++;//printing first col

	 first_col++;
  }

  printf("\nCircular matrix is as follows:\n\n");

  for( i = 0 ; i < order; i++ )
  {
 	  for( j = 0 ; j < order ; j++)
	   printf("%d\t", arr[i][j]);
 	 printf("\n");
  }

 return 0;
}
