/*
example of the string tokenizer
*/

import java.util.StringTokenizer;
public class Simple{
	public static void main (String args[])
	{
		StringTokenizer st=new StringTokenizer("my name is Dev"," ");
		while(st.hasMoreTokens())
		{
			System.out.println(st.nextToken());
		}
	}
}