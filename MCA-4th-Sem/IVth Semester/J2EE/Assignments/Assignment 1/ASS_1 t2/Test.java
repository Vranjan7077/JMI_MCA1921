import java.sql.*;
import java.util.*;

class ConnectionManager
{  
	static Stack<Connection> ConnectionPool = new Stack<Connection>();
	static
	{
		try
		{
			Class.forName("oracle.jdbc.driver.OracleDriver");
			Connection con[] = new Connection[100];
			for(int i=0;i<100;i++)
			{
				con[i]=DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:XE","system","system");
				ConnectionPool.push(con[i]);
			}
		}
		catch(Exception e){}
	}
	
	static Connection getConnection()
	{
		return (ConnectionPool.pop());
	}
	
	static void putConnection(Connection dummy)
	{
		ConnectionPool.push(dummy);
	}
	
	static int availableConnection()
	{
		return ((int)ConnectionPool.size());
	}
}

class MyThread extends Thread
{
	public void run() 
    { 
		try
		{
			Connection con= ConnectionManager.getConnection();
			String username = getRandomString();
			String password = getRandomString();
			Statement st= con.createStatement();
			String q="insert into users values('"+username+"','"+password+"')";
			if(st.executeUpdate(q)==1)
			{
				System.out.println("Data Successfully Inserted");
			}
			ConnectionManager.putConnection(con);
			con.close();
		}
		catch(Exception e)	{System.out.println(e);}
    }	
	
	static String getRandomString() 
	{
        String SALTCHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        StringBuilder salt = new StringBuilder();
        Random rnd = new Random();
        while (salt.length()<8) 
		{
            salt.append(SALTCHARS.charAt(rnd.nextInt(25) + 1));
        }
        String saltStr = salt.toString();
        return saltStr;
    }
}

public class Test
{
	public static void main(String args[])
	{
		MyThread T[]= new MyThread[100];
		for(int i=0;i<100;i++)
		{
			T[i]=new MyThread();
		}
		
		for(int i=0;i<100;i++)
		{
			T[i].start();
		}
	}
}