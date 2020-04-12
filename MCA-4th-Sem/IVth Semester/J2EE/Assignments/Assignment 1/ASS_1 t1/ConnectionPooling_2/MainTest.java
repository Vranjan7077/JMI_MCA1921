import java.util.Scanner;

public class MainTest
{
	public static void main(String args[])
	{
		Thread MainThread = Thread.currentThread();
		System.out.println("Size Of ConnectionPool before= "+ConnectionManager.availableConnection());
		//Scanner sc= new Scanner(System.in);
		//System.out.println("Enter the No of Thread Required: ");
		int count=1000;
		MyThread T[]= new MyThread[count];
		try{
			for(int i=0;i<count;i++)
			{
				T[i]=new MyThread();
			}
			MainThread.sleep(100);
		}catch(InterruptedException e) {System.out.println(e);}
		
		System.out.println(MyThread.successful+" Data Inserted Successfully.");
		System.out.println((count-MyThread.successful)+" Threads unable to get connection.");
	}
}