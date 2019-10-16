//
//jmi_p6-1.c on 12-08-18
//
//programe to ...
//For more info. about array of strings Read : https://www.includehelp.com/c-programs/create-and-print-array-of-strings.aspx

#include <stdio.h>

int main()
{
	int i, n, rate_phr;
  char buffer[255];
	int w_hr[n];
	int gross_pay[n];
  char name[n][30]; // each name can be of max. len 30

  label1:
	printf("\nEnter no of employee:\t");
	scanf("%d", &n);

	if(n <= 0)
	{
		printf("\nInvalid input...!Try Again.");
    goto label1;
	}

	label2:
	printf("\nEnter rate/hr:\t");
	scanf("%d", &rate_phr);

	if( rate_phr <= 0)
	{
		printf("\n\nInvalid input...!");
    goto label2;
	}

	printf("\n\n");
	for (i = 0; i < n; i++)
	{
		printf("\nEnter name of employee %d:\t", i + 1);
		fgets(buffer, sizeof(buffer), stdin); // clearing input stream
		scanf("%[^\n]s", name[i] );

    label3:
		printf("Enter total working hours:\t");
		scanf("%d", &w_hr[i]);

		if(w_hr[i] <= 0)
		{
			printf("\n\nInvalid input...!");
			goto label3;
		}

		if(w_hr[i] <= 40)
		{
			gross_pay[i] = w_hr[i] * rate_phr;
		}
		else
		{
			int excess = w_hr[i] - 40;

			gross_pay[i] = 40 * rate_phr + (excess * rate_phr) / 2;
		}
	}

	printf("\n\nData of employee are as follows:\n\n");
	printf("\nS.no\tNames\tGross_pay\n\n");

	for(i = 0; i < 40; i++,printf("-")) ;

	for(i = 0; i < n; i++)
	{
		printf("\n%d)\t %s\t %d", i + 1, name[i], gross_pay[i]);
	}

	return 0;
}
