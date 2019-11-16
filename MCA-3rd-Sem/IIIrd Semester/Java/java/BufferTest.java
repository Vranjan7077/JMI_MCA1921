/*
//Java Program to demonstrate the use of StringBuffer class.
*/
pubic class BufferTest{
	public static void main (String[] args)
	{
		StringBuffer buffer=new StringBuffer("Hello");
		buffer.append("world");
		System.out.println(buffer);
	}
}

/*
//Java Program to demonstrate the use of StringBuilder class.
*/
pubic class BuilderTest{
	public static void main (String[] args)
	{
		StringBuilder builder=new StringBuilder("Hello");
		builder.append("world");
		System.out.println(builder);
	}
}