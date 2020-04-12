import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;
import org.xml.sax.SAXParseException;

class XMLReader
{
	static Document doc;
	static File xmlFile;
	static File file;
	static FileWriter f;
	static String OutputFilePath="output.csv";
	static String allTags = "";
	
	static void setOPath(String p)
	{
		 OutputFilePath=p;
	}
	
	static void Convert(String filepath) throws SAXParseException, SAXException, ParserConfigurationException, IOException, Exception
	{
		file = new File(OutputFilePath);
		f = new FileWriter(file);
		
		if (!file.exists())
			file.createNewFile();
			
		xmlFile = new File(filepath);
		DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
		dbFactory.setValidating(true);
		DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
		
		dBuilder.setErrorHandler(new XMLErrorHandler());
		doc = dBuilder.parse(xmlFile); 
		Element root=doc.getDocumentElement();
		f.write("Root Node Name= ("+ root.getTagName()+")\n\n");
		f.flush();
		f.write("name,course,semester,state,email,mobile\n");
		f.flush();
		parse(root);
	}
	
	static void parse(Element el) throws IOException
	{
		NodeList children = el.getChildNodes();
        for (int i = 0; i < children.getLength(); i++)
		{
            Node n = children.item(i);
            if (n.getNodeType() == Node.ELEMENT_NODE) 
			{
				Element e=(Element)n;
                parse(e);
            }
			else
			{
				if(n.getTextContent().trim().length() > 0)
				{
					f.write(n.getTextContent()+",");
					f.flush();
				}
				if(i==(children.getLength()-1) && children.getLength()>1)
				{
					f.write("\n");
					f.flush();
				}
			}
        }
	}
}	