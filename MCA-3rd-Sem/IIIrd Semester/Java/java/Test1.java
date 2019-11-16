import java.io.*;
import java.util.*; 
class Test1
{
	public static void main(String[] args)
	{
		StringBuffer s = new StringBuffer("Vinay");
		int p= s.length();
		int q=s.capacity();
		System.out.println("length of the String Vinay="+p);
		System.out.println("capacity of the String Vinay="+q);
	}
}