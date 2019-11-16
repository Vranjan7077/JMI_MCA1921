/*
String and StringBuffer HashCode Test
*/
public class InstanceTest
{  
    public static void main(String args[])
    {  
   // generating the hashcode of the string 	
        System.out.println("Hashcode test of String:");  
        String str="DevOps";  
        System.out.println(str.hashCode());  
        str=str+"Anonyomous";  
        System.out.println(str.hashCode());  
  // generating the Hashcode of the string buffer 
        System.out.println("Hashcode test of StringBuffer:");  
        StringBuffer sb=new StringBuffer("DevOps");  
        System.out.println(sb.hashCode());  
        sb.append("Anonyomous");  
        System.out.println(sb.hashCode());  
    }  
}  