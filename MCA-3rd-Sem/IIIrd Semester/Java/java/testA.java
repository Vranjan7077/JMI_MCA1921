/*
example of StringBuilder class
1. append()
2. insert()
*/

class testA{
	public static void main(String args[])
	{
 		StringBuilder sb=new StringBuilder("hii");
 		sb.append("hello");
 		System.out.println(sb);
	}
}

class testI{
	public static void main(String args[])
	{
		StringBuilder sb=new StringBuilder("Hey");
		sb.insert(1,"hello");
		System.out.println(sb);
	}
}