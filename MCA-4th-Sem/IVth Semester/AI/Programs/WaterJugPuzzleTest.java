package waterjugpuzzle;
import java.util.*;
class WaterJugPuzzle1{
    static int a=0;
    static int b=0;
    //Queue<Integer> q= new LinkedList<Integer>();
     public void fillA()
   {
       if(a<=4) {a=4;
               System.out.println(a+","+b);}
   }
   public void fillB()
   {
       if(b<=3) {b=3;System.out.println(a+","+b);}
   }
   public void emptyAintoB()
   {
       if((a+b)>0 && (a+b)>=4 && b>0)
       {
      a=a-(3-b);
      b=3;
     System.out.println(a+","+b);
   }}
   public void emptyBintoA()   {
        if((a+b)>0 && (a+b)>=3)
       {
      a=4;
     b=b-(4-a);
     System.out.println(a+","+b);
       }
   }
}
public class WaterJugPuzzleTest {
    public static void main(String[] args) {
    Scanner scan=new Scanner(System.in);
    WaterJugPuzzle1 w=new  WaterJugPuzzle1();
   /* System.out.println("enter the capacity of jug 1 : ");
   int a=scan.nextInt();
     System.out.println("enter the capacity of jug 2 : ");
     int b=scan.nextInt();*/
     w.fillA();
     w.fillB();
     w.emptyAintoB();
     w.emptyBintoA();
    }
    
}
