import java.lang.math; 
import java.util;
class area
{
   public static void main(String args[]) 
    {        
      int a,b,c;
      float s,area;
      Scanner s= new Scanner(System.in);
      a=in.nextInt();
      b=in.nextInt();
      c=in.nextInt();
      if(a+b>c||b+c>a||a+c>b)
      {
        s=(a+b+c)/2;
        area=Math.sqrt(s*(s-a)*(s-b)*(s-c));
        System.out.println("The area of the traingle is :" +area);
      }
      else
      {
         System.out.println("The area of the traingle is not possible ");
      }
   }
}