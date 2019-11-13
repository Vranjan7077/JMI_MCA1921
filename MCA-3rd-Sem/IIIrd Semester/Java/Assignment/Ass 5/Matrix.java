/*
The given question is :
Define a generic java class Matrix which resembles a 2D array of matrix of size mxn. 
The dimension of the matrix (m,n) can be taken as a constructor argument. 
The matrix class has a method called populateData() which generates the random values 
between a range and store it to the matrix. This class also overrides the toString() 
method so that matrix objects can be directly printed using System.out.println(). 
Create 20 objects of the matrix class and store it to an array list. 
Test your program for integer numbers as well as complex numbers.
[Hints: You need to define a class for complex numbers. The Matrix objects may be created as follows:

Matrix <Integer> m1 = new Matrix <Integer> (5, 6);
Matrix <Complex> M1 = new Matrix <Complex> (4, 6);
m1.populateData();
M2.populateData();
....
]
*/
import java.util.*;
import java.lang.reflect.Array;

// this class is for generating the complex and the imaginary part of the matrix
class complex
{
    int real,imag;
    public complex(int real,int imag)
    {
        this.real=real;
        this.imag=imag;
    }
    
    public String toString()

    {
        return real+"+"+imag+"i";
    }
}

// this class is for generating the matrix 
public class Matrix <T>
{
	int row,col;
	Object varType;
	public Object a[][];

	public Matrix(int row,int col)
	{
    	this.row=row;
    	this.col=col;
  		  T[][] array=(T[][])new Object[row][col];
    	  a=array;
	}
	public void populateData(Object o)
	{
    	Random random=new Random();
    	if(o instanceof Integer)
    	{
    		for(int i=0;i<a.length;i++)
    		{
        		for(int j=0;j<a[0].length;j++)
        		{
            		a[i][j]=random.nextInt(10);
        		}
    		}
    	}
     	if(o instanceof complex)
     	{
        	for(int i=0;i<a.length;i++)
         		{
         			for(int j=0;j<a[0].length;j++)
          			{
            			a[i][j]=new complex(random.nextInt(10),random.nextInt(10));
          			}
         		}
     	}
    
	}
public String toString()
{
    String s="";
    for(int i=0;i<a.length;i++)
    {
        for(int j=0;j<a[0].length;j++)
        {
            s=s+a[i][j]+" ";
        }
        s+="\n";
                
    }
    return s;
	}
}


class Test
{
   public static void main(String args[])
   {
    Matrix <complex> m2=new Matrix<complex>(5,6);
    complex ob1=new complex(0,0);
    m2.populateData(ob1);
    System.out.println(m2);
  	 }
   }
