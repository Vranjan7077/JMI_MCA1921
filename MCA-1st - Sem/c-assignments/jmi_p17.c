//
//jmi_p17.c on 20-08-18
//
//programe to find smallest number
#include<stdio.h>

int main()
{
	int num1, num2, num3, result;

	printf("\nEnter an number :\t");
	scanf("%d", &num1);

	printf("\nEnter an number :\t");
	scanf("%d", &num2);

	printf("\nEnter an number :\t");
	scanf("%d", &num3);

	if( num1 < num2 )
  {
   if(num1 < num3)
    result = num1;
   else
    result = num3;
  }
	else
	{
	 if(num2 < num3)
    result = num2;
   else
    result = num3;
	}

	printf("\n%d is smallest.", result);
	return 0;
}
