/*
Write a program that takes paragraph as a input from user and display the occurrence index of each character.
*/
/*
Write a program that takes paragraph as a input from user and display the occurrence index of each character.
*/
import java.util.*;


class Main { 
  static void occuringIndexChar(String s){
      HashMap<Character, ArrayList<Integer>> mp = new HashMap<>();
      for (int i = 0; i < s.length(); i++){
        if(mp.containsKey(s.charAt(i))){
            mp.get(s.charAt(i)).add(i);
        }else{
          mp.put(s.charAt(i), new ArrayList<Integer>(Arrays.asList(i)));
        }

      }
      for (Character i : mp.keySet()) {
        System.out.println("Indexes of Occurrences of char " + i + " is: " + mp.get(i));
      }            
  }

    public static void main(String[] args) { 
    	  String s; 
        Scanner sc = new Scanner(System.in); 
        System.out.println("Enter a string"); 
        s = sc.nextLine();
        occuringIndexChar(s); 
        sc.close();
    } 
}


/*
import java.util.*;
import java.util.Scanner;
class NoOfOccurenceOfCharacters 
{ 
    static final int MAX_CHAR = 256;   
    static void getOccuringChar(String str) 
    { 
        // Create an array of size 256 i.e. ASCII_SIZE 
        int count[] = new int[MAX_CHAR]; 
        int len = str.length();
        // Initialize count array index 
        for (int i = 0; i < len; i++) 
            count[str.charAt(i)]++; 
        // Create an array of given String size 
        char ch[] = new char[str.length()]; 
        for (int i = 0; i < len; i++) 
        { 
            ch[i] = str.charAt(i); 
            int find = 0; 
            for (int j = 0; j <= i; j++) 
            { 
                // If any matches found 
                if (str.charAt(i) == ch[j])  
                    find++;                 
            } 
  
            if (find == 1)  
                System.out.println("Number of Occurrence of " +str.charAt(i) + " is:" + count[str.charAt(i)]);             
        } 
    } 
    public static void main(String[] args) 
    { 
    	String s; 
        Scanner sc = new Scanner(System.in); 
        System.out.println("Enter a string"); 
        s = sc.nextLine();
        getOccuringChar(s); 
    } 
} 
*/