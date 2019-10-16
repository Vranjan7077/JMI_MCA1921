//
//
//
//

#include<iostream>
#include<stdlib.h>
#include<stack>


using namespace std;

int main()
{
  int choice;
  stack <int> s;

  while(1)
  {
    cout << endl << endl << "  1 -> Push Element";
    cout << endl << "  2 -> Pop Element";
    cout << endl << "  3 -> See Top Element";
    cout << endl << "  4 -> Get Size";
    cout << endl << "  5 -> Isempty";
    cout << endl << "  0 -> Exit";

    do{
       cout << endl << "  Enter your choice : \t";
       cin >> choice;

       if(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 0 )
        cout << "Invalid input...! Try Again.";
      }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 0);

    switch(choice)
    {
      case 1: cout << endl << "Enter element : ";
              int item; cin >> item;
              s.push(item);
              cout << endl << item << " is pushed in stack.";
              break;

      case 2: if(s.empty())
               cout << endl << "Stack Underflow...!";
              else
               {
                 int item = s.top();
                 s.pop();
                 cout << endl << item << " is poped from stack.";
               }
              break;

      case 3: if(s.empty())
               cout << endl << "Stack Underflow...!";
              else
              cout << endl << "Top = " << s.top();
              break;

      case 4: cout << endl << "Size of stack is : " << s.size();
              break;

      case 5: if(s.empty())
               cout << endl << "Yes, Stack is Empty!";
              else
               cout << endl << "No, Stack is Not Empty!";
              break;

      case 0: exit(EXIT_SUCCESS);
    }
  }
}
