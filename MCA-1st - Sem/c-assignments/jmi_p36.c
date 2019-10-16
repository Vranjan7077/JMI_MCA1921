//
//jmi_p36.c on 14-10-18
//
//programe to perform addition, subtraction, and multiplication of matrix using one dimension array

#include<stdio.h>
#include<stdlib.h>


void get_dimensions_for_addition_or_subtraction(int *rows, int *cols)
{
  printf("\nEnter no of rows :\t");
  scanf("%d", rows);
  printf("\nEnter no of columns :\t");
  scanf("%d", cols);
}

void get_dimensions_for_multiplication( int *rows1, int *cols1, int *rows2, int *cols2 )
{
	printf("\nEnter no of rows of matrix \'A\':\t");
	scanf("%d", rows1);
	printf("\nEnter no of cols of matrix \'A\':\t");
	scanf("%d", cols1);
	printf("\n\nEnter no of rows of matrix \'B\':\t");
	scanf("%d", rows2);
	printf("\nEnter no of cols of matrix \'B\':\t");
	scanf("%d", cols2);

  if( *cols1 != *rows2 )
	{
		printf("\nMultiplication not Possible...!");
	  exit(EXIT_FAILURE);
	}
}

void get_matrix( int *arr1, int *arr2, int rows1, int cols1, int rows2, int cols2 )
{
	int i, j;

	 printf("\nEnter elements of martix \'A\':\n");
	 for( i = 0 ; i < rows1 ; i++ )
	 {
	 	for( j = 0 ;  j  < cols1 ; j++ )
	 	{
	 		printf("A[%d][%d] > ", i + 1, j + 1 );
	 		scanf("%d", ( arr1 + i * cols1 + j ) );
		}
		printf("\n");
	 }

	 printf("\nEnter elements of martix \'B\':\n");
	 for( i = 0 ; i < rows2 ; i++)
	 {
	 	for( j = 0 ;  j  < cols2 ; j++)
	 	{
	 		printf("B[%d][%d] > ", i + 1, j + 1 );
	 		scanf("%d", ( arr2 + i * cols2 + j ) );
		}
		printf("\n");
	 }
}

void add_or_sub_matrix(int *arr1, int *arr2, int *arr3, int rows, int cols, int choice)
{
	int i, j;

  for( i = 0 ; i < rows * cols ; i++ )
  {
	 if(choice == 1 )
	 arr3[i] = arr1[i] + arr2[i];
   else
   arr3[i] = arr1[i] - arr2[i];
  }
}

void multiply_matrix( int *arr1, int *arr2, int *arr3, int rows1, int cols1, int rows2, int cols2, int rows3, int cols3 )
{
	int i, j, k, sum;

	for( i = 0 ; i < rows1 ; i++ )
	  {
	   for( j = 0 ; j < cols2 ; j++ )         /*computing matrix multiplication*/
	    {
	      sum = 0;
	      for( k = 0 ; k < cols1 ; k++)
	      {
			   sum += *(arr1 + i * cols1 + k) * ( *(arr2 + k * cols2 + j) );
			   *(arr3 + i * cols3 + j) = sum;
		    }
	    }
	  }
}

void put_matrix(int *arr1, int rows, int cols, char ch)
{
	int i, j;

	printf("\nMatrix \'%c\' : \n", ch);

	 for( i = 0 ; i < rows ; i++)
	 {
	 	 for( j = 0 ;  j  < cols ; j++)
	 	  printf("%d\t", *( arr1 + i * cols + j ) );
		printf("\n");
	 }
}

int main()
{
	int arr1[50], arr2[50], arr3[50];
	int rows1, cols1, rows2, cols2, rows3, cols3, choice;

	printf("\n1 for Matrix Addition.");
	printf("\n2 for Matrix Subtraction.");
	printf("\n3 for Matrix Multiplication.");

	do{
	   printf("\n\nEnter your choice:\t");
	   scanf("%d", &choice);
		 if( choice != 1 && choice != 2 && choice != 3 ) printf("\nInvalid Input...! Try Again.");
	  }while( choice != 1 && choice != 2 && choice != 3 );

	if(choice == 1 || choice == 2)
	{
		get_dimensions_for_addition_or_subtraction(&rows1, &cols1);
	  rows2 = rows1;
	  cols2 = cols1;
	  rows3 = rows1;
	  cols3 = cols1;
	}
	else
	{
		get_dimensions_for_multiplication(&rows1, &cols1, &rows2, &cols2);
		rows3 = rows1; // resultant matrix order
	  cols3 = cols2;
	}

  get_matrix( arr1, arr2, rows1, cols1, rows2, cols2 );

	if(choice == 1 || choice == 2)
		add_or_sub_matrix(arr1, arr2, arr3, rows1, cols1, choice);
	else
		multiply_matrix( arr1, arr2, arr3, rows1, cols1, rows2, cols2, rows3, cols3 );

	put_matrix(arr1, rows1, cols1, 'A');
  put_matrix(arr2, rows2, cols2, 'B');

	if(choice == 1)
	 printf("\n\nMatrix \'C\' = \'A\' + \'B\' : \n");
	else if(choice == 2)
	 printf("\n\nMatrix  \'C\' = \'A\' - \'B\' is : \n");
	else
	 printf("\n\nMatrix  \'C\' = \'A\' * \'B\' is : \n");

	 put_matrix(arr3, rows3, cols3, 'C');

	return 0;
}
