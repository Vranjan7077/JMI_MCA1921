import javax.swing.*;
import java.util.*;

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
	void input()
	{	
		System.out.println("Enter the no of rows and cols of matrix ");
		Scanner sc=new Scanner(System.in);
		row=sc.nextInt();
		col=sc.nextInt();
		a=new int[row][col];
		i++;
	}
	void MatrixGenerate()
	{
		Random rd=new Random();
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				a[i][j]=rd.nextInt();
	}
    Matrix MatrixAddition(Matrix m)
	{
		Matrix m3=new Matrix(row,col);
			for(int i=0;i<row;i++)
				for(int j=0;j<col;j++)
					m3.a[i][j]=a[i][j]+m.a[i][j];
		return m3;
	}
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
class test
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		Matrix m1=new Matrix();
		Matrix m2=new Matrix();
		Matrix m4;
		char ch;
		do
		{
			System.out.println("Which operation would you like to perform");
			System.out.println("1.Matrix Addition");
			System.out.println("2.Matrix product");
			System.out.println("Choose one operation");
			int a=sc.nextInt();
			switch(a)
			{
				case 1: m1.input();
						m2.input();
						if(m1.row!=m2.row || m1.col!=m2.col)
							System.out.println("Matrix Addition  is not possible");
						else
						{
							m1.MatrixGenerate();
							m2.MatrixGenerate();
						//	m1.print();
						//	m2.print();
							System.out.println("Matrix Addition:\n");
							m4=m1.MatrixAddition(m2);
							m4.print();
						}
						break;
				case 2: m1.input();
						m2.input();
						if(m1.col!=m2.row)
							System.out.println("Matrix product not possible");
						else
						{  //System.out.println("here");
							m1.MatrixGenerate();
							m2.MatrixGenerate();
							m1.print();
						    m2.print();
							//long start=System.currentTimeMillis();
							m4=m1.MatrixProduct(m2);
							//long end=System.currentTimeMillis();
							//System.out.println("Time taken by product operation= " + (end-start) + " ms");
						    System.out.println("Matrix product: ");
						    m4.print();
						}
						break;
				default:System.out.println("Wrong choice");
			}
		System.out.println("Do you want to continue(y/n)");
		ch=sc.next().charAt(0);
		}
		while(ch == 'y' || ch=='Y');
	}
}
				