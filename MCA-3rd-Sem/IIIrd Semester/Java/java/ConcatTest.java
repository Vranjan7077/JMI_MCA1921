/*
Performance Test of String and StringBuffer
*/
public class ConcatTest
{  
    // calculating the time taken by the string 
    public static String concatWithString()    
    {  
        String t = "DevOps";  
        for (int i=0; i<10000; i++){  
            t = t + "Anonyomous";  
        }  
        return t;  
    }  
  // calculating the time taken by the string buffer  
    public static String concatWithStringBuffer()
    {  
        StringBuffer sb = new StringBuffer("DevOps");  
        for (int i=0; i<10000; i++){  
            sb.append("Anonyomous");  
        }  
        return sb.toString();  
    }  
    public static void main(String[] args)
    {  
        long startTime = System.currentTimeMillis();  
        concatWithString();  
        System.out.println("Time taken by Concating with String: "+(System.currentTimeMillis()-startTime)+"ms");  
        startTime = System.currentTimeMillis();  
        concatWithStringBuffer();  
        System.out.println("Time taken by Concating with  StringBuffer: "+(System.currentTimeMillis()-startTime)+"ms");  
    }  
}  