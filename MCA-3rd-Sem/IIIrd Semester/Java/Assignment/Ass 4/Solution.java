import java.util.*;
import java.io.*;

public class Solution4
{
    static List<String> kmers = new ArrayList<>();
    static List<Integer> frequency = new ArrayList<>();

    public static void permutations(String str, String prefix, int k) 
    {         
        if (k == 0)
        { 
            if( !(kmers.contains(prefix)) )
                kmers.add(prefix);

            return; 
        } 
        for (int i = 0; i < str.length(); i++)
          permutations(str, prefix + str.charAt(i), k - 1);
    }
    
    public static void setFrequency(String DNA, int k)
    {
        int count;
        String kmr;

        for(int i = 0 ; i < kmers.size() ; i++)
        {
            count = 0;
            kmr = kmers.get(i);

            for(int j = 0 ; j < DNA.length() - kmr.length() + 1 ; j++) // count occurence of kmer in DNA
                if(kmr.equals(DNA.substring(j, j + kmr.length())) )
                    count++;

            frequency.add(count);
        }
    }
    
    public static void saveRecord()
    {
        try
        {
            String kmersString = "";
            String occurenceString = "";

            for(int i = 0 ; i < kmers.size() ; i++)
            {
                kmersString += kmers.get(i) + " ";
                occurenceString += frequency.get(i) + " ";
            }            
            String filePath = "Solution4.csv";
            FileWriter fw = new FileWriter(filePath, true);  // true === append, false === overwrite
            BufferedWriter bw = new BufferedWriter(fw);
            PrintWriter pw = new PrintWriter(bw);
            pw.println(kmersString + "\n" + occurenceString);
            pw.flush();
            pw.close();
        }
        catch(Exception e)
        {
            System.out.println("Error Occured...!");
        }
    }
    public static void main(String []args)
    {
        int k;
        String DNA;    
        Scanner scan = new Scanner(System.in);

        System.out.print("Enter DNA : ");
        DNA = scan.nextLine();
        System.out.print("Enter value of k : ");
        k = scan.nextInt();

        permutations(DNA, "", k);
        setFrequency(DNA, k);
        
        System.out.println();
        for(int i = 0 ; i < kmers.size() ; i++)
            System.out.print(kmers.get(i) + " ");
        
        System.out.println();
        for(int i = 0 ; i < frequency.size() ; i++)
            System.out.print(frequency.get(i) + " ");

        saveRecord();
    }
}