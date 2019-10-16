//
//
//
//
#include<iostream>
using namespace std;

class Point
{
public: // public data members x, y
   int x, y;
   Point(){}
   Point(int a, int b)
   {
      x = a;
      y = b;
   }
   friend ostream& operator << (ostream & out,Point p)
   {
     out <<"(" << p.x << "," << p.y << ") ";
   }
};

class Stack
{
   Point *a;
   int length, tos;
public:
   Stack(int n)
   {
     a = new Point[n];
     length = n;
     tos = -1;
   }
   bool isEmpty()
   {
     if(tos == -1) return true;
     else return false;
   }
   void push(Point p){ a[++tos] = p; }
   Point pop(){ return a[tos--]; }
   void display();
   int gettos(){ return tos; }
};

void Stack::display()
{
//we have to print path from start for we will display points from bottom of the stack rather than display it from top

 for(int i = 0 ; i <= tos ; i++) cout<<a[i]; // calling function to print value
}

int main()
{
  int r, c;

  do{
      cout << endl << "Enter no. of rows in maze : ";
      cin >> r;
      cout << endl << "Enter no. of columns in maze : ";
      cin >> c;

     if(r < 1 || c < 1) cout << "Invalid no. of rows/cols...! Try again." << endl;
    }while(r < 1 || c < 1);

  int maze[r][c];
  Stack s(r * c - 1);


  cout << endl << "Enter maze elements(0/1) : " << endl;
  for(int i = 0 ; i < r ; i++)
  {
    for(int j = 0 ; j < c ; j++)
    {
      if((i == 0 && j == 0) || (i == r - 1 && j == c - 1) )
      {
        maze[0][0] = maze[r - 1][c - 1] = 0; //we don't have to read the source and destination
        continue;
      }
      do{
         cout << "Maze[" << i + 1 << "][" << j + 1 << "] > ";
         cin >> maze[i][j];

         if(maze[i][j] != 0 && maze[i][j] != 1) cout << "Invalid input...! Try again." << endl;
        }while(maze[i][j] != 0 && maze[i][j] != 1);
    }
    cout << endl;
  }

  cout << endl << "MAZE" << endl;
  for(int i = 0 ; i < r ; i++)
  {
     for(int j = 0 ; j < c ; j++) cout << maze[i][j];
    cout << endl;
  }

  int row = 0, col = 0;
  while(row < r - 1 || col < c - 1)
  {                                            // we assume if a[i][j] == 1 then its occupied rat has to see other directions to move
    if(col < c - 1 && maze[row][col + 1] == 0) //right
    {
      Point p(row, col);
      s.push(p);
      col++;
      maze[row][col] = 1;
    }
    else if(row < r - 1 && maze[row + 1][col] == 0) //down
    {
      Point p(row, col);
      s.push(p);
      row++;
      maze[row][col] = 1;
    }
    else if(col > 0 && maze[row][col - 1] == 0) //left
    {
      Point p(row, col);
      s.push(p);
      col--;
      maze[row][col] = 1;
    }
    else if(row > 0 && maze[row - 1][col] == 0) //up
    {
      Point p(row, col);
      s.push(p);
      row--;
      maze[row][col] = 1;
    }
    else
    {
      if( s.isEmpty() == true ) break; //stack is empty

     Point p = s.pop(); //no path available so backtrack
     row = p.x;
     col = p.y;
    }
  cout << endl;
 } //end of while

  if(s.isEmpty() && r != 1 && c != 1)            //if the source and destination is same
   cout << endl << "There is no path available.";
  else
  {
   cout<<"The path is : ";
   s.display();
   cout << "(" << r - 1 << ", " << c - 1 << ")" << endl; // printing last one
  }

  return 0;
}
