import java.util.*;
import java.lang.Math;

class triangle
{	public static void main(String args[])
	{	int a,b,c,l,sum,ot;
		double s,area;
		
		Scanner S=new Scanner(System.in);
		System.out.println("Enter values of a,b,c");
		a=S.nextInt();
		b=S.nextInt();
		c=S.nextInt();

		l=a;
		l=l>b?l:b;
		l=l>c?l:c;

		if( l==a )
		{	sum=b+c;
			ot=a;
		}
		else if ( l==b )
		{	sum=a+c;
			ot=b;
		}
		else
		{	sum=a+b;
			ot=c;
		}
		
		if ( sum > ot)
		{	System.out.println(" The area could be found since "+ot+" is the larger side and is less than the sum of other two sides");
			
			s=(a+b+c)/2;
			area = Math.sqrt(s*(s-a)*(s-b)*(s-c));
			
			System.out.println("Area = "+area);
		}
		else
			System.out.println("Triangle could not be formed");
	}
}