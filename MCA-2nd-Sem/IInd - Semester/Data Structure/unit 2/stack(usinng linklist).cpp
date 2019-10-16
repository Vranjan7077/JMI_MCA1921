#include<iostream>
#include<stdlib.h>

using namespace std;

class node{
  int data;
  node *link;
  friend class stack;
};

class stack{
  node *top;
  int count;
public:
  stack()
  {
    top = NULL;
    count = 0;
  }
  void push(int);
  void pop();
  void gettop();
  int size();
  bool isempty();
  void displayall()
  {
    if(top == NULL)
      cout << endl << "Stack overflow...!";
   else
   {
     node* cur = top;
     cout << endl << "stack element are as : ";

     while(cur)
      cout << cur->data << " ", cur = cur->link;
   }
 }

};

void stack::push(int item)
{
    if(top == NULL)
    {
      top = new node;
      top->link = NULL;
      top->data = item;
   }
    else
    {
     node *newnode = new node;
      newnode->data = item;
      newnode->link = top;
      top = newnode;
     }
    count++;
    cout << item << " is Pushed into stack.";
  }

void stack::pop()
{
  if(isempty())
   cout << endl << "Stack Underflow...!";
  else
  {
    int item;
    node* del;

    if(count == 1)
    {
      del = top;
      item = del->data;
      top = NULL;
    }
    else
    {
      del = top;
      item = del->data;
      top = top->link;
    }
    count--;
    delete del;
    cout << item << " is poped from stack.";
  }
}

void stack::gettop()
{
  if(count == 0)
    cout << endl << "Stack Underflow...!";
  else
    cout << top->data << " is Top Element.";
}
int stack::size()
{
  return (count);
}

bool stack::isempty()
{
  if(top== NULL)
   return true;
  else
   return false;
}

int main()
{
  int choice, item;
  stack s;

  while(1)
  {
    cout << endl << endl << "  1 -> Push Element";
    cout << endl << "  2 -> Pop Element";
    cout << endl << "  3 -> See Top Element";
    cout << endl << "  4 -> Get Size";
    cout << endl << "  5 -> Isempty";
    cout << endl << "  0 -> Exit";
    cout << endl << " -1 -> Clear screen";

    do{
       cout << endl << "  Enter your choice : \t";
       cin >> choice;

       if(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5  && choice != 0 && choice != -1)
        cout << "Invalid choice, Please enter correct choice...!";
      }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 0 && choice != -1);

    switch(choice)
    {
      case 1: cout << endl << "Enter element : ";
              cin >> item;
              s.push(item);
              break;

      case 2: s.pop();
              break;

      case 3: s.gettop();
              break;

      case 4: cout << endl << "Size of stack is : " << s.size();
              break;

      case 5: if(s.isempty())
               cout << endl << "Yes, Stack is Empty!";
              else
               cout << endl << "No, Stack is Not Empty!";
              break;
      case 0: exit(EXIT_SUCCESS);
              break;
      case -1:system("clear");
              break;
     }
  }
  return 0;
}
