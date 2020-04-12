package puzzle8test;
class Puzzle8
{  
    int startState[][] = {{6,2,5}, {1,0,8}, {7,4,3}};
    int i,j,m;
 public void left()
 {
     
     m=startState[1][0];
startState[1][0]=startState[1][1];
startState[1][1]=m;
     for(i=0;i<3;i++)
     {
         for(j=0;j<3;j++)
             System.out.print(" "+startState[i][j]);
         System.out.println();
     }
      System.out.println("------------------------------");
 }
 public void right()
 {
     m=startState[1][2];
     startState[1][2]=startState[1][1];
     startState[1][1]=m;
     for(i=0;i<3;i++)
     {
         for(j=0;j<3;j++)
             System.out.print(" "+startState[i][j]);
         System.out.println();
     }
      System.out.println("------------------------------");
 }
 public void top()
 {
     m=startState[0][1];
     startState[0][1]=startState[1][1];
     startState[1][1]=m;
     for(i=0;i<3;i++)
     {
         for(j=0;j<3;j++)
             System.out.print(" "+startState[i][j]);
         System.out.println();
     }
      System.out.println("------------------------------");
 }
 public void bottom()
 {
     m=startState[2][1];
     startState[2][1]=startState[1][1];
     startState[1][1]=m;
     for(i=0;i<3;i++)
     {
         for(j=0;j<3;j++)
             System.out.print(" "+startState[i][j]);
         System.out.println();
     }
 }
}
public class Puzzle8Test {
    public static void main(String[] args) {
        
    Puzzle8 p=new Puzzle8();
    p.left();
    p.right();
    p.top();
    p.bottom();
    }
    
}
