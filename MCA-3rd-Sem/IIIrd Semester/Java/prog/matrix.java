import javax.swing.*;
import java.util.*;
class test
{
	public static void main(string args[])
	{
	int m,n,p,q,c,d,k,sum=0;
	Scanner sc= new Scanner(System.in);
	System.out.println("Enter the no.of rows and columns");
	m=sc.nextInt();
	n= sc.nextInt();
	int first[][]= new Int[m][n];
	System.out.println("Enter elements:");
	for(c=0;c<m;c++)
	{
		for(d=0;d<n;d++)
		{
			first[c][d]=sc.nextInt();
		}
	}
	System.out.println("Enter the no.of.rows and columns");
	p= sc.nextInt();
	q=sc.nextInt();
	if(n!=p)
	{
		System.out.println("The matrix can't be multiplied");
	}
	else
	{
		int second[][]=new int[p][q];
		int mul[][]=new int[m][q];
		System.out.println("Enter elements ");
		for(c=0;c<p;c++)
		{
			for (d=0;d<q;d++)
			{
				second[c][d]=sc.nextInt();
			}
		}
		long d1= System.CurrentTimenulls();
		for(c=0;c<m;c++)
	{
		for(d=0;d<q;d++)
		{
			for(k=0;k<p;k++)
			{
				sum=sum+first[c][k]*second[k][d];
			}
			mul[c][d]=sum;
			sum=0;
		}
	}
	System.out.println("Product of matrix:");
	for(c=0;c<m;c++)
	{
		for(d=0;d<q;d++)
		{
			System.out.println(mul[c][d]+"\t");
		}
		System.out.println("\n");
	}
	long d2=System.CurrentTimenulls();
	long diff=d2-d;
	System.out.println(diff);
	testt t= new testt();
	t.sum();
	t.display();
	}

	}
}
class testt
{
	public static void main()
	{
		for(c=0;c<m;c++)
		{
			for(d=0;d<n;d++)
			{
				sum[c][d]=first[c][d]+second[c][d];
			}
		}
		public  void display()
		{
			System.out.println("sum of matrix");
			for(c=0;c<m;c++)
			{
				for(d=0;d<n;d++)
				{
					System.out.println(sum[c][d]+" ");
				}
				System.out.println(" ");
			}
	    }
    }
}    
