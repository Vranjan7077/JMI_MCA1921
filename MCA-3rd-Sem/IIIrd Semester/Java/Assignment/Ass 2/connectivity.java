/*

*/
import java.util.*;
class Graph_class
{
int a[][];
Graph_class(int a1[][])
   {
   	this.a=a1;
   }
// to display the answer of the given matrix after performing all the steps required
void display()
{
   for(int i=0;i<a.length;i++)
      {
        for(int j=0;j<a[i].length;j++)
           { 
            System.out.print(a[i][j]);
           }
         System.out.println();
      }
}

void isconnected()
{                                                //USING WARSHALLL ALGORITHM FOR CONNECTIVITY
int count=0;
for(int it=0;it<a.length;it++)
          {
              for(int j=0;j<a.length;j++)
             {
                 for( int k=0;k<a[j].length;k++)
                { 
                    if(it!=j && k!=it)
                    {   
                        if(a[it][k]+a[j][it]==2)
                             a[j][k]=1;
                        
                    }
                }
                 
             }
         }
    for(int i=0;i<a.length;i++)
    {
      for(int j=0;j<a[i].length;j++)
        {
          if(a[i][j]==1)
            count++;
        }   
    }

if(count==a.length*a.length)
  System.out.println("The Given Graph is Connected");
else 
  System.out.println("The Given Graph is Not Connected");
  }
};

class Graph_class2 extends Graph_class
{
  Graph_class2(int a[][])
  {
   super(a);}
   void degree()
    {
      int indegree=0;
      int outdegree=0;
      for(int i=0;i<a.length;i++)
      { 
          indegree=0;
          outdegree=0;
          for(int j=0;j<a[i].length;j++)
          {
            if(a[i][j]>0)
               outdegree++;
            if(a[j][i]>0)
               indegree++;
          }

System.out.println("Indegree: "+indegree+"\tOutdegree: "+outdegree);}
}
void display()
  {
    super.display();
  }
};

// class to find the shortest path
class path extends Graph_class
{
	path(int a[][])
	{
	super(a);
	}
	//Flyod warshall Algorithm 
  /*
  The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path problem. 
  The problem is to find shortest distances between every pair of vertices in a given 
  edge weighted directed Graph.
  */
	void spath(int q,int p)
	{                                              
 	for(int it=0;it<a.length;it++)
          {
              for(int j=0;j<a.length;j++)
             {
                 for( int k=0;k<a[j].length;k++)
                { 
                    if(it!=j && k!=it)
                    {   
                        if(a[it][k]+a[j][it]<a[j][k])
                             a[j][k]=a[it][k]+a[j][it];
                        
                    }
                }
                 
             }
         }
  System.out.println("\nMinimum Distance Between Vertex " + q + " to Vertex "+p+"="+a[q][p]);
           
	}
}
class connectivity
{
  public static void main(String args[])
    { 
    	int n=0;
   		Scanner ini= new Scanner(System.in);
      	System.out.print("Enter the size of array you want to find the path:\n ");
      	n=ini.nextInt();
        int a1[][]=new int[n][n]; 
          System.out.println("Enter the adjancy matrix element:");
               for(int i=0;i<a1.length;i++)
                {
                  for(int j=0;j<a1[i].length;j++)
                     {
                     	a1[i][j]=ini.nextInt();
					 }
                }
       Graph_class2 g2=new Graph_class2(a1);
       path p1=new path(a1);
       g2.degree();
       g2.display();
       p1.isconnected();
       p1.spath(0,1);
    }
}