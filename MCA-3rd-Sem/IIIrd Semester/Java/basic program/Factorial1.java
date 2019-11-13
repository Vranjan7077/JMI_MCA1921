import javax.swing.*;
import java.math.*;

public class Factorial
{
   publich static void main(String[] args)
   {
     BigInteger fact=BigInteger.valueOf(1);
     String input=JoptionPane.showInputDialog ("Enter a number you want a factorial");
     int x=Integer.parseInt(input);
     for(int i=1;i<=x;i++)
     {
       fact=fact.multiply(BigInteger.valueOf(i));
     }
    JOptionPane.showMessageDialog(null,"factorial is :"+fact);
}
 