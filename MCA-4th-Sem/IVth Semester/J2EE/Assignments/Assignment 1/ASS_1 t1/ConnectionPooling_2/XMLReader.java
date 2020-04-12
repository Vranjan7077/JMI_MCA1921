import java.io.File;
import java.io.IOException;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

class XMLReader
{
	static Document doc;
	
	static
	{
		String filePath = "config.xml";
		File xmlFile = new File(filePath);
		DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
		DocumentBuilder dBuilder;
		try 
		{
			dBuilder = dbFactory.newDocumentBuilder();
			doc = dBuilder.parse(xmlFile);
			doc.getDocumentElement().normalize();
		}
		catch(SAXException | ParserConfigurationException e)
		{
			e.printStackTrace();
		}
		catch(IOException e)
		{
			System.out.println("File not found at given directory.");
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
	
	static String get(String tag)
	{
		NodeList nodeList = doc.getElementsByTagName(tag).item(0).getChildNodes();
		Node node = (Node) nodeList.item(0);
		return node.getNodeValue();
	}
}