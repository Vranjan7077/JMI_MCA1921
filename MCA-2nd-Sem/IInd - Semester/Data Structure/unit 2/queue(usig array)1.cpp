//queue(using_array).cpp on 18-03-19
//
//Program to implement queue using array
//

#include<iostream>
#include<stdlib.h>

using namespace std;

class queue{
  int *arr, front, rear, maxsize;
public:
  queue(int maxsize)
  {
    arr = new int [maxsize];
    this->maxsize = maxsize;
    front = -1;
    rear = -1;
  }
  void enqueue(int);
  void dequeue();
  void peek();
  int size();
  bool isempty();
  bool isfull();
};

void queue::enqueue(int item)
{
  if(rear == maxsize - 1)
   cout << endl << "Queue Overflow...!";
  else
  {
     if(rear == -1)
       front++;
   arr[++rear] = item;
   cout << arr[rear] << " is Inserted into Queue.";
 }
}

void queue::dequeue()
{
  if(front == -1)
   cout << endl << "Queue Underflow...!";
  else
  {
   int item = arr[rear];
     if(rear == front)
      front = rear = -1;
     else
      front++;
   cout << endl << item << " is Deleted from Queue.";
  }
}

void queue::peek()
{
  if(front == -1)
    cout << endl << "Queue Underflow...!";
  else
    cout << arr[front] << " is Front Element.";
}

int queue::size()
{
  if( front == -1)
  return 0;
  else
  return (rear - front + 1);
}
bool queue::isempty()
{
  if(front == -1)
   return true;
  else
   return false;
}
bool queue::isfull()
{
  if(rear == maxsize -1)
   return true;
  else
   return false;
}

int main()
{
  int maxsize, choice, item;

  do{
     cout << endl << endl << "Enter Max Size of Queue : ";
     cin >> maxsize;

     if(maxsize < 1) cout << "Invalid Input...! Try Again.";
    }while(maxsize < 1);

  queue q(maxsize);

  while(1)
  {
    cout << endl << endl << "  1 -> Enqueue Element";
    cout << endl << "  2 -> Dequeue Element";
    cout << endl << "  3 -> Peek";
    cout << endl << "  4 -> Size";
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
      case 1: cout << endl << "Enter element : ";
              cin >> item;
              q.enqueue(item);
              break;

      case 2: q.dequeue();
              break;

      case 3: q.peek();  //Gets the front element of the queue
              break;

      case 4: cout << endl << "Size of Queue is : " << q.size();
              break;

      case 5: if(q.isempty())
               cout << endl << "Yes, Queue is Empty!";
              else
               cout << endl << "No, Queue is Not Empty!";
              break;

      case 6: if(q.isfull())
               cout << endl << "Yes, Queue is Full!";
              else
               cout << endl << "No, Queue is Not Full!";
              break;

      case 0: exit(EXIT_SUCCESS);
    }
  }
}
