/*
The k-mer refers to all the possible substrings of length k that are contained in a string. 
In genomics, k-mers refer to all the possible subsequences (of length k) in a given DNA Sequence. 
The number of possible k-mers given n possibilities (n=4 in the case of DNA e.g. ACTG) is n^k. 
For example, if k=1, there are 4 k-mers possible (i.e. A, C, T, G), in case of k=2, 16 k-mers are possible 
(e.g. AA AT AC AG TA TT TC TG CA CT CC CG GA GT GC GG). Write a program which takes a DNA sequence file and 
value of k as input from the user, and calcualte the occurce of k-mers, and store it to a CSV file. 

[For example, 

if given DNA sequence 

S=ATTGCCC, 

k=2, 

then output should be as follows:

AA AT AC AG TA TT TC TG CA CT CC CG GA GT GC GG

0 1 0 0 0 1 0 1 0 0 2 0 0 0 1 0
*/
import java.util.*;
import java.io.*;

public class Prog4
{
    static List<String> kmers = new ArrayList<>();
    static List<Integer> frequency = new ArrayList<>();

//class for finding the permutations of the given DNA so that we can find the frequency afterwards.
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

//class for finding the frequency of the DNA means how many times does it occur     
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

//class for saving the record of the file in the EXCel or CSV    
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
            String filePath = "Prog4.csv";
            FileWriter fw = new FileWriter(filePath, true);  // true === append, false === overwrite
            BufferedWriter bw = new BufferedWriter(fw);
            PrintWriter pw = new PrintWriter(bw);
            pw.println(kmersString + "\n" + occurenceString);
            pw.flush();
            pw.close();
        }
        // handling the exception in the program if the user give the wrong input and print the output Error comes 
        // on the screen.
        catch(Exception e)
        {
            System.out.println("Error Occured...!");
        }
    }
// main class in which all the calculations are performed like printing the DNA and taking the value of the K and DNA 
//from the user so that we can find the frequency and printing it.    
    public static void main(String []args)
    {
        int k;
        String DNA;    
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter the value of the DNA : ");
        DNA = scan.nextLine();
        System.out.print("Enter value of k : ");
        k = scan.nextInt();
        permutations(DNA, "", k);
        setFrequency(DNA, k);
// for printing the output of the given DNA
        System.out.println();
        System.out.println("The given frequency of the K-Mers is :\n");
        for(int i = 0 ; i < kmers.size() ; i++)
            System.out.print(kmers.get(i) + " ");
// for printing the frequency of the given DNA
        System.out.println();
        System.out.println("The given frequency of the DNA is :\n");
        for(int i = 0 ; i < frequency.size() ; i++)
            System.out.print(frequency.get(i) + " ");
        saveRecord();
    }
}