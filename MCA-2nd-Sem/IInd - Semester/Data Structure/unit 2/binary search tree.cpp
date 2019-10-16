//binary_tree.cpp on 20-03-19
//
//program to implement binary search tree using linked list
//
#include<iostream>
#include<stdlib.h>
#include<queue>

using namespace std;

class bst;
class node{
   node *left, *right;
   int data;
 public:
   node()
   {
    left = right = NULL;
   }
   friend class bst;
 };

 class bst{
   node* root;
 public:
   bst(){root = NULL;}
   void build(node*);
   void inorder(node*);
   void preorder(node*);
   void postorder(node*);
   void levelorder();
   int search(node*, int, int);
   int height(node*);
   bool isempty()
   {
    if(root == NULL) return true;
    else return false;
   }
   node* getroot(){return root;}
};

 void bst::build(node* r)
 {
   char choice;

   if(r == NULL) root = new node, r = root;

   cout << endl << "Enter data : ";
   cin >> r->data;

   cout << endl << "Does node(" << r->data << ") has Left child y/n : ";
   cin >> choice;

   if(choice == 'y' || choice == 'Y')
     r->left = new node, build(r->left);

   cout << "Does node(" << r->data << ") has Right child y/n : ";
   cin >> choice;

   if(choice == 'y' || choice == 'Y')
     r->right = new node, build(r->right);
 }

 void bst::inorder(node* r)
 {
   if(r->left != NULL)
    inorder(r->left);
   cout << r->data << " ";
   if(r->right != NULL)
    inorder(r->right);
 }

 void bst::preorder(node* r)
 {
   cout << r->data << " ";
   if(r->left != NULL)
    preorder(r->left);
   if(r->right != NULL)
    preorder(r->right);
 }

 void bst::postorder(node* r)
 {
   if(r->left != NULL)
    postorder(r->left);
   if(r->right != NULL)
    postorder(r->right);
   cout << r-> data << " ";
 }

 void bst::levelorder()
 {
  int front, rear;
   front = rear = -1;
   node* queue[100];

   front++;
   queue[++rear] = root;
   node* cur;

   while(rear != -1) // while queue is not empty
   {
     cur = queue[front];
     cout << cur->data << " ";

     if(cur->left != NULL)
       queue[++rear] =cur->left;
     if(cur->right != NULL)
       queue[++rear] =cur->right;

    if(++front > rear) // dequeue element and chech whether a queue is empty
     front = rear = -1; //empty queue;
   }
  }
/*################## METHOD 2 for levelorder traversal ######################*/

/* level order traversal using standard template library 'queue' in header file
 void bst::levelorder()
 {
  queue <node*> Q;
  Q.push(root);
  node* cur;
  while(!Q.empty())
  {
   cur  = Q.front();
   cout << cur->data << " ";
    if(cur->left != NULL)
      Q.push(cur->left);
    if(cur->right != NULL)
      Q.push(cur->right);
   Q.pop();
}*/
int bst::height(node * r)
{
  if(r == NULL)
    return 0;

  int left_height = height(r->left);
  int right_height = height(r->right);

  if(left_height > right_height)
   return left_height + 1;
  else
   return right_height + 1;
}
/* there is a small issue in this while using static variable and calling it repeatedly from main
assume a condition while entering key elememts to find and suppose it found then the value of 'isfound = 1'
and now may to search other elements again in that dase the value of is 'isfound=1' the last value as we
are not able to reinitialize it with 0 each time when called it from main()
As we kown the static variable has file scope rather than function scope means its is destroyed only program exits
*/

int bst::search(node* r, int key, int reset)
 {
  static int isfound = 0;

  if(reset == 1) isfound = 0, reset = 0; // will reset the value of isfound = 0 each time it is called from main()

   if(r->data == key) isfound = 1;;

   if(!isfound)
   {
    if(r->left != NULL)
      search(r->left, key, reset);
   }

   if(!isfound)
   {
    if(r->right != NULL)
      search(r->right, key, reset);
    return isfound;
   }
 }

int main()
{
   bst tree;
   int x;
   int choice;

   while(1)
   {
     cout << endl << endl << " 1-> Build Tree";
     cout << endl << " 2-> Inorder Traversal";
     cout << endl << " 3-> Preorder Traversal";
     cout << endl << " 4-> Postorder Traversal";
     cout << endl << " 5-> Levelorder Traversal";
     cout << endl << " 6-> Height of tree";
     cout << endl << " 7-> Search Element";
     cout << endl << " 0-> Exit.";
     cout << endl << "-1-> clear screen.";

     cout << endl << "Enter your choice : ";
     cin >> choice;

     switch(choice)
     {
       case 1: if(tree.getroot() == NULL)
                tree.build(tree.getroot());
               else
                cout << endl << "Binary Tree already created...!";
               break;

       case 2: if(tree.isempty())
                cout << "Empty Binary Search Tree.";
               else
               {
                cout << endl << "Inorder traversal is : ";
                tree.inorder(tree.getroot());
               }
              break;

       case 3: if(tree.isempty())
               cout << "Empty Binary Search Tree.";
               else
               {
                cout << endl << "Preorder traversal is : ";
                tree.preorder(tree.getroot());
               }
               break;

       case 4: if(tree.isempty())
               cout << "Empty Binary Search Tree.";
               else
               {
                cout << endl << "Postorder traversal is : ";
                tree.postorder(tree.getroot());
               }
               break;
       case 5: if(tree.isempty())
               cout << "Empty Binary Search Tree.";
               else
               {
                cout << endl << "Levelorder traversal is : ";
                tree.levelorder();
               }
               break;
       case 6: if(tree.isempty())
               cout << "Empty Binary Search Tree.";
               else
                cout << endl << "Height of tree is : " << tree.height(tree.getroot());
               break;

       case 7: if(tree.isempty())
                cout << "Empty Binary Search Tree.";
               else
               {
                 int item;
                 cout << endl << "Enter key element : ";
                 cin >> item;

                 if(tree.search(tree.getroot(), item , 1)) // return true if found otherwise return 0
                  cout << endl << "Element found.";
                 else
                  cout << endl << "Element not found.";
               }
               break;

       case 0: exit(0);
               break;
       case -1:system("clear");
               break;
       default: cout << "Invalid choice ....!";
     }
   }
 return 0;
}
