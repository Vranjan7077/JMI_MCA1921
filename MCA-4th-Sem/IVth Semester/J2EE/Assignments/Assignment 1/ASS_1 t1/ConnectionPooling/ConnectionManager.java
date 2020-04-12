import java.sql.*;
import java.util.*;
 
class ConnectionManager
{  
	static Stack<Connection> ConnectionPool = new Stack<Connection>();
	static
	{
		try
		{
			Class.forName(XMLReader.get("Driver"));
			Connection con[] = new Connection[100];
			for(int i=0;i<100;i++)
			{
				con[i]=DriverManager.getConnection(XMLReader.get("URL"),XMLReader.get("username"),XMLReader.get("password"));
				ConnectionPool.push(con[i]);
			}
		}
		catch(SQLException e)	{System.out.println(e);}
		catch(ClassNotFoundException e){}
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