//
//jmi_p28.c on 27-08-18
//
//programe to compute distance between two points
//
// Use cmd to Run from terminal 'gcc jmi_p28.c -lm'
//Note: Read article for more info. if u want to run this program from linux Terminal
// https://www.includehelp.com/c-programming-questions/compiling-program-with-math-library-linux.aspx

#include<stdio.h>
#include<math.h>

double square( double n ){ return(n * n); }

double distance(double x1, double y1, double x2, double y2)
{
  int x, y;

  x = square(x2 - x1);
  y = square(y2 - y1);

  return sqrt ( x + y );
}

int main()
{
	double x1, y1, x2, y2;

	printf("\nEnter Coordinates (X1, Y1) =\t");
	scanf("%lf%lf", &x1, &y1);
  printf("\nEnter Coordinates (X2, Y2) =\t");
	scanf("%lf%lf", &x2, &y2);

	printf("\nDistance between p1(%.2lf,%.2lf) and p2(%.2lf,%.2lf) is %.2lf.", x1, y1, x2, y2, distance(x1, y1, x2, y2));

	return 0;
}
