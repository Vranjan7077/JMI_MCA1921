import org.xml.sax.ErrorHandler;
import org.xml.sax.SAXParseException;

class XMLErrorHandler implements ErrorHandler 
{
	public void error(SAXParseException exception) throws SAXParseException
	{
        throw exception;
	}

	public void fatalError(SAXParseException exception) throws SAXParseException 
	{
		throw exception;
	}

	public void warning(SAXParseException exception) throws SAXParseException 
	{
		throw exception;
	}
}

class CustomException extends Exception
{
	CustomException(String s)
	{
		super(s);
	}
}