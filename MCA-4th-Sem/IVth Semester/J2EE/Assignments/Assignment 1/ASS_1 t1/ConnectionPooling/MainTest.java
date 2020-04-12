import java.util.Scanner;

public class MainTest
{
	public static void main(String args[])
	{
		System.out.println("Size Of ConnectionPool before= "+ConnectionManager.availableConnection());
		Scanner sc= new Scanner(System.in);
		System.out.println("Enter the No of Thread Required: ");
		int count=sc.nextInt();
		MyThread T[]= new MyThread[count];
		try{
		for(int i=0;i<count;i++)
		{
			T[i]=new MyThread();
			T[i].join();
		}	
		}catch(InterruptedException e) {System.out.println(e);}
	}
}