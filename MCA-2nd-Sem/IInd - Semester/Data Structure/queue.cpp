//
//
//
//

#include<iostream>
#include<stdlib.h>
#include<queue>

using namespace std;

int main()
{
  int choice, item;
  queue <int> q;

  while(1)
  {
    cout << endl << endl << "  1 -> Push Element";
    cout << endl << "  2 -> Pop Element";
    cout << endl << "  3 -> See Front Element";
    cout << endl << "  4 -> See Back Element";
    cout << endl << "  5 -> Get Size";
    cout << endl << "  6 -> Isempty";
    cout << endl << "  0 -> Exit";

    do{
       cout << endl << "  Enter your choice : \t";
       cin >> choice;

       if(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 0 )
        cout << "Invalid input...! Try Again.";
      }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5  && choice != 6 && choice != 0);

    switch(choice)
    {
      case 1: cout << endl << "Enter element : ";
              int item; cin >> item;
              q.push(item);
              cout << endl << item << " is Added in Queue.";
              break;

      case 2: if(q.empty())
               cout << endl << "Queue Underflow...!";
              else
               {
                 item = q.front();
                 q.pop();
                 cout << endl << item << " is Removed from stack.";
               }
              break;

      case 3: if(q.empty())
               cout << endl << "Queue Underflow...!";
              else
              cout << endl << "Front = " << q.front();
              break;
      case 4: if(q.empty())
               cout << endl << "Queue Underflow...!";
              else
               cout << endl << "Back = " << q.back();
              break;

      case 5: cout << endl << "Size of Queue is : " << q.size();
              break;

      case 6: if(q.empty())
               cout << endl << "Yes, Queue is Empty!";
              else
               cout << endl << "No, Queue is Not Empty!";
              break;

      case 0: exit(EXIT_SUCCESS);
    }
  }
}
