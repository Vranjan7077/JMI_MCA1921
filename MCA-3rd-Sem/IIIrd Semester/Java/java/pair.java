import java.util.*;
import java.util.Scanner;

class pair<T>
{
	T first;
	T second;
	public pair (T f, T s)
	{
		first =f;
		second=s;
	}
	public pair()
	{
		first=null;
		second=null;
	}
	void swap()
	{
		T third;
		third= first;
		first=second;
		second=third;
	}
	void display()
	{
		System.out.println(first);
		System.out.println(second);
	}
}
class test
{
	public static void main(String args[])
	{
		pair<String>s=new pair<String><"JMI","JNU">;
		s.swap();
		s.display();
	}
}