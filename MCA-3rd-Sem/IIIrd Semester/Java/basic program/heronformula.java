import java.util.*;
import java.lang.Math;
class heronformula
{	public static void main(String args[])
	{	int a,b,c,l,sum,other;
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
			other=a;
		}
		else if ( l==b )
		{	sum=a+c;
			other=b;
		}
		else
		{	sum=a+b;
			other=c;
		}
		
		if ( sum > other)
		{	System.out.println(" The area could be found since "+other);
			s=(a+b+c)/2;
			area = Math.sqrt(s*(s-a)*(s-b)*(s-c));
			System.out.println("Area = "+area);
		}
		else
			System.out.println("Triangle could not be formed with the given sides");
                        System.out.println("Please try with some other sides");

	}
}