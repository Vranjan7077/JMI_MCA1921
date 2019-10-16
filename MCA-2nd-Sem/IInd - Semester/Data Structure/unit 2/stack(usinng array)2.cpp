//stack(using_array)-2.cpp on 18-03-19
//
//Program to implement stack using array
//

#include<iostream>
#include<stdlib.h>

using namespace std;

class stack{
  int *arr,tos, maxsize;
public:
  stack(int maxsize)
  {
    arr = new int [maxsize];
    this->maxsize = maxsize;
    tos = -1;
  }
  void push(int);
  void pop();
  int top();
  int size();
  bool isempty();
  bool isfull();
};

void stack::push(int item)
{
  arr[++tos] = item;
  cout << arr[tos] << " is Pushed into stack.";
}

void stack::pop()
{
  cout << arr[tos--] << " is poped from stack.";
}

int stack::top()
{
  return (arr[tos]);
}

int stack::size()
{
  return (tos + 1);
}
bool stack::isempty()
{
  if(tos == -1)
   return true;
  else
   return false;
}
bool stack::isfull()
{
  if(tos == maxsize -1)
   return true;
  else
   return false;
}

int main()
{
  int maxsize, choice, item;

  do{
     cout << endl << endl << "Enter Max Size of stack : ";
     cin >> maxsize;

     if(maxsize < 1) cout << "Invalid input...! Try Again.";
    }while(maxsize < 1);

  stack s(maxsize);

  while(1)
  {
    cout << endl << endl << "  1 -> Push Element";
    cout << endl << "  2 -> Pop Element";
    cout << endl << "  3 -> See Top Element";
    cout << endl << "  4 -> Get Size";
    cout << endl << "  5 -> Isempty";
    cout << endl << "  6 -> Isfull";
    cout << endl << "  0 -> Exit";

    do{
       cout << endl << "  Enter your choice : \t";
       cin >> choice;

       if(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 0)
        cout << "Invalid input...! Try Again.";
      }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 0);

    switch(choice)
    {
      case 1: if(s.isfull())
                cout << endl << "Stack Overflow...!";
              else
              {
                cout << endl << "Enter element : ";
                cin >> item;
                s.push(item);
              }
              break;

      case 2: if(s.isempty())
               cout << endl << "Stack Underflow...!";
              else
              {
               s.pop();
              }
              break;

      case 3: if(s.isempty())
               cout << endl << "Stack Underflow...!";
              else
              {
               cout << s.top() << " is Top Element.";
              }
              break;

      case 4: cout << endl << "Size of stack is : " << s.size();
              break;

      case 5: if(s.isempty())
               cout << endl << "Yes, Stack is Empty!";
              else
               cout << endl << "No, Stack is Not Empty!";
              break;

      case 6: if(s.isfull())
               cout << endl << "Yes, Stack is Full!";
              else
               cout << endl << "No, Stack is Not Full!";
              break;

      case 0: exit(EXIT_SUCCESS);
    }
  }
}
