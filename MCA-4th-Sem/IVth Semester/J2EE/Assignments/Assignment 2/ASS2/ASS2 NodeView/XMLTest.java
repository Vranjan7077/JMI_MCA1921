import org.xml.sax.SAXParseException;
import java.io.FileNotFoundException;

class XMLTest
{
	public static void main(String arg[])
	{		
		try
		{
			String path="config.xml";
			
			if(arg.length==1)
				path=arg[0];
			else if(arg.length==2)
			{
				path=arg[0];
				XMLReader.setOPath(arg[1]);
			}
			else if(arg.length>2)
				throw new CustomException("Number of CommandLine Argument Exceeds...");
		
			XMLReader.Convert(path);
			System.out.println("Operation successfull...");
		}
		catch(FileNotFoundException e) {System.out.println("XML File Not Found...");}
		catch(SAXParseException e) {System.out.println("Invalid XML Document. Validation of XMl Failed...");}
		catch(Exception e) {System.out.println(e);}
	}
}