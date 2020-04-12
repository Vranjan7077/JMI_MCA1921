import java.sql.*;
import java.util.Random;
import java.util.EmptyStackException;
import net.ucanaccess.jdbc.UcanaccessSQLException;

class MyThread extends Thread
{
	MyThread()
	{
		start();
	}

	public void run() 
    { 
		try
		{
			Connection con= ConnectionManager.getConnection();
			String username = getRandomString();
			String password = getRandomString();
			Statement st= con.createStatement();
			String q="insert into user_master values('"+username+"','"+password+"')";
			if(st.executeUpdate(q)==1)
			{
				System.out.println("Data Inserted Successfully");
			}
			ConnectionManager.putConnection(con);
		}
		catch(EmptyStackException e){System.out.println("Unable to get Connection");}
		catch(UcanaccessSQLException e) {System.out.println("Unable to get Connection");}
		catch(SQLException e){System.out.println(e);}
		catch(Exception e){System.out.println(e);}
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