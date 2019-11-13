import java.util.*;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.*;
import java.io.*;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStream;
public class Palindromic
{

   public boolean isPalindromic(String str)
    {
        boolean tem=false;
        for(int i=0,j=str.length()-1;i<str.length()/2;i++,j--)
        {
            

             
               if(str.charAt(i)!=str.charAt(j))
               {
                tem=false;
                break;
               }
               else if(str.charAt(i)==str.charAt(j))
               {
                tem=true;
               }
               

               
        }
		return tem;

    }
    
     private  void writeUsingBufferedWriter(TreeSet data,int len) {
        String fileName = "out.txt"; 
        try { 
            
            
            // Open given file in append mode. 
                 
            BufferedWriter out = new BufferedWriter( 
                   new FileWriter(fileName, true));
                   out.newLine();
                   out.write("Length "+len+": ["); 
                   Iterator<String> itr = data.iterator();
                   while(itr.hasNext()){
                       String str=itr.next();
                    out.write(str); 
                        out.append(",");
                    out.flush();
                  }
                  out.write("]"); 
            
            out.close(); 
        } 
        catch (IOException e) { 
            System.out.println("exception occoured" + e); 
        } 
    }
    synchronized public void  genPl(String  str,int len)
    {
        TreeSet<String> obj=new TreeSet<String>();
       int sze=len,k=len;
        for(int i=0;i<str.length()-sze;i++)
        {
             
                boolean check=isPalindromic(str.substring(i,k));
                if(check==true)
                {
                    obj.add(str.substring(i,k));
                   

                }

            
            k++;
        }
        Palindromic p=new Palindromic();
        p.writeUsingBufferedWriter(obj,len);
        obj.clear();
    }
    public  static void main(String []args)
    {
        try { 
        BufferedReader in = new BufferedReader( new FileReader("test.txt")); 
        String str=in.readLine();
        
        Palindromic pn=new Palindromic();
        //Create Fixed 5 thread Which When finshed his tak Get New Auto task by usinng Thread pooling
        ExecutorService executor=Executors.newFixedThreadPool(5);
        for(int i=2;i<10;i++)
        {
            Runnable worker=new MyThread(pn, i,str);
            executor.execute(worker);
        }
        executor.shutdown();
        /* while(executor.isTerminated())
        System.out.println("FNished All Thread" ); */
    

    }catch (IOException e) { 
        System.out.println("Exception Occurred" + e); 
    } 
}
}


class MyThread extends Thread {
    Palindromic pn;
    int len;
    String str;
    MyThread(Palindromic pn,int len,String str)
    {
        this.pn=pn;
        this.len=len;
        this.str=str;
    }
    
    public void run() {
     System.out.println(Thread.currentThread().getName()+" Start");
        pn.genPl(str, len);
        try{
        Thread.sleep(500);
        }
        catch(InterruptedException e)
        {
            e.printStackTrace();
        }
        System.out.println(Thread.currentThread().getName()+" End");
    }

    }
    
