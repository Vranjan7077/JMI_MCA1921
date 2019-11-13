import java.util.*;
import javax.swing.*;

class Matrix
{
  int [][]arr;
  int r,c;
  Matrix(int m,int n)
  {
    r=m;c=n;
    arr=new int[r][c];
    Random ran=new Random();
    for(int i=0;i<r;i++)
       for(int j=0;j<c;j++)
          arr[i][j]=ran.nextInt(10);
  }
  
  Matrix()
  {
    r=c=500;
    Random ran=new Random();
    arr=new int[500][500];
    for(int i=0;i<500;i++)
       for(int j=0;j<500;j++)
          arr[i][j]=ran.nextInt();
  }
  // sum matrix to make the sum throught the given input values of n and m 
  Matrix sum(Matrix b)
  { 
    if(r == b.r && c==b.c){
      Matrix C=new Matrix(r,c);
      for(int i=0;i<r;i++)
       for(int j=0;j<c;j++)
         C.arr[i][j]=arr[i][j]+b.arr[i][j];
      return C;
    }
    else
    {   
      return null;
    }
  }
  // Multiply the matrix to make the throught the given input values of n and m 
  Matrix mul(Matrix B)
  {
    if(c == B.r)
    {
       Matrix C=new Matrix(r,B.c);
       for(int i=0;i<r;i++){
          for(int j=0;j<B.c;j++){
	     C.arr[i][j]=0;
        	for(int k=0;k<c;k++)
        	   C.arr[i][j]+=arr[i][k]*B.arr[k][j];
	  }    
	}
return C;     
  }
else
return null;
}
  void display()
{
    for(int i=0;i<r;i++)
     {
      for(int j=0;j<c;j++)
	{
        System.out.print("\t"+arr[i][j] );
	}
     System.out.println(); 
     }	
  }
};

public class test{
  public static void main(String []args){
    Matrix A=new Matrix(3,4);
    Matrix B=new Matrix(3,4);
    Matrix C=new Matrix(3,4);
    String a;
        
while(true)
    {
        a=JOptionPane.showInputDialog("enter your choice  \n1:  Sum \n 2:  Multiplication \n 3:  display \n 4:  exit" );
	switch(a)
	{
		case "1":
			{
				C=A.sum(B);
				if(C!=null)
					C.display();
				else
					System.out.println("The sum of the given array with input");
				break;
			}
		case "2":
			{
				//long start=System.currentTimeMillis();
				long start=System.nanoTime();
				C=A.mul(B);
 				long end=System.nanoTime();
				if(C!=null){
					C.display();
					System.out.println("time taken for multiplication is(in ns) :" +(start-end));
				}
				else
					System.out.println("multiplication not possible");
				break;
			}
		case "3":
			{
				A.display();
				B.display();
				break;
			}
		case "4":
			{
				System.exit(0);	
			}	
	    }

	}  
  }
}