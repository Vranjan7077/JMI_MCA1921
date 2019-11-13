import javax.swing.*;
import java.util.*;
//here we are making the class matrix so that we can make the array of the given values of rows and col.
class Matrix
{
	int row,col;
	int a[][];
	static int i=1;
	Matrix(){}
	Matrix(int row,int col)
	{
		this.row=row;
		this.col=col;
		a=new int[this.row][this.col];
	} 
	// here we are taking the input from the user to get the input values of the row and col.
	void input()
	{	
		System.out.println("Enter the value of N and M (n*m): ");
		Scanner sc=new Scanner(System.in);
		row=sc.nextInt();
		col=sc.nextInt();
		a=new int[row][col];
		i++;
	}
// generating the matrix of random number throught the given input values of n and m 
	void MatrixGenerate()
	{
		Random rd=new Random();
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				a[i][j]=rd.nextInt(100);
	}
// sum matrix to make the sum throught the given input values of n and m 
    Matrix MatrixAddition(Matrix m)
	{
		Matrix m3=new Matrix(row,col);
			for(int i=0;i<row;i++)
				for(int j=0;j<col;j++)
					m3.a[i][j]=a[i][j]+m.a[i][j];
		return m3;
	}
// subtract matrix to get the result throught the given input values of n and m 
    Matrix MatrixSubtraction(Matrix m)
	{
		Matrix m3=new Matrix(row,col);
			for(int i=0;i<row;i++)
				for(int j=0;j<col;j++)
					m3.a[i][j]=a[i][j]-m.a[i][j];
		return m3;
	}

// Multiply the matrix to make the throught the given input values of n and m 
	Matrix MatrixProduct(Matrix m)
	{  
		Matrix m3=new Matrix(row,m.col);
			for(int i=0;i<row;i++)
				for(int j=0;j<m.col;j++)
				{
					m3.a[i][j]=0;
					for(int k=0;k<col;k++)
						m3.a[i][j]+=a[i][k]*m.a[k][j];
				}
		return m3;
	}
//here we are printing the values of the matrix after the given input values of the rows and col.
	void print()
	{
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
				System.out.print(a[i][j] + " ");
			System.out.println();
		}
	}
}
public class testmat
{
	public static void main(String args[])
	{
		String a= new String();
		Scanner sc=new Scanner(System.in);
		Matrix m1=new Matrix();
		Matrix m2=new Matrix();
		Matrix m4;
		char ch;
		do
		{
			a=JOptionPane.showInputDialog("Enter your choice\n1:Matrix Addition\n2:Matrix Subtraction\n3:Matrix product\n4.Exit");
			switch(a)
			{
				case "1": m1.input();
						m2.input();
						if(m1.row!=m2.row || m1.col!=m2.col)
							System.out.println("Matrix Addition  is not possible\n");
						else
						{
							m1.MatrixGenerate();
							m2.MatrixGenerate();
							System.out.println("*******************");
							System.out.println("\nMatrix A:\n");
							m1.print();
							System.out.println("*******************");
							System.out.println("\nMatrix B:\n");
						    m2.print();
							long start=System.nanoTime();
							System.out.println("*******************");
							System.out.println("\nMatrix Addition:");
							m4=m1.MatrixAddition(m2);
							m4.print();
							long end=System.nanoTime();
							System.out.println("\nTime taken by Addition operation= " + (end-start) + " ns");
							System.out.println("*******************");
						}
						break;
				case "2":	m1.input();
				        m2.input();
				        if(m1.row!=m2.row||m1.col!=m2.col)
				        System.out.println("Matrix Subtraction is not possible\n");
				        else
				        {
				        	m1.MatrixGenerate();
				        	m2.MatrixGenerate();
				        	System.out.println("*******************");
				        	System.out.println("\nMatrix A:\n");
							m1.print();
							System.out.println("*******************");
							System.out.println("\nMatrix B:\n");
						    m2.print();
							long start=System.nanoTime();
							System.out.println("*******************");
				        	System.out.println("\nMatrix Subtraction:");
				        	m4=m1.MatrixSubtraction(m2);
				        	m4.print();
				        	long end=System.nanoTime();
							System.out.println("\nTime taken by Subtraction operation= " + (end-start) + " ns");
							System.out.println("*******************");
				        }
				        break;	
				case "3": m1.input();
						m2.input();
						if(m1.col!=m2.row)
							System.out.println("Matrix product not possible\n");
						else
						{  
							m1.MatrixGenerate();
							m2.MatrixGenerate();
							System.out.println("*******************");
							System.out.println("\nMatrix A:\n");
							m1.print();
							System.out.println("*******************");
							System.out.println("\nMatrix B:\n");
						    m2.print();
						    System.out.println("*******************");
							long start=System.nanoTime();
							m4=m1.MatrixProduct(m2);
							System.out.println("*******************");
						    System.out.println("\nMatrix product: ");
						    m4.print();
						    long end=System.nanoTime();
						    System.out.println("\nTime taken by product operation= " + (end-start) + " ns");
						    System.out.println("*******************");
						}
						break;
				case "4": System.exit(1);
				        break;
			}
		}
		while(a != "4");
	}
}
				