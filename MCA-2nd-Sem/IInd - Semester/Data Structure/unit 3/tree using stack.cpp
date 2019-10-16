//
//
//
//
#include<iostream>
#include<math.h>

using namespace std;

class tree{
	int *arr;
	int height, maxsize;
public:
	tree(int h)
	{
		height = h;
		maxsize = pow(2, height) - 1; // that much memory location needed to store the full complete binary tree 
		arr = new int[maxsize];
	}
	bool hasLeftChild(int i)
	{
		if ( 2 * i + 1 < maxsize)  // has left child we **can't use <= maxsize as the last element can't be left child even though is index is  <= maxsize
		 return true;
		else
		 return false;
	}
	bool hasRightChild(int i)
	{
		if ( 2 * i + 2 < maxsize)  // has left & right child
		 return true;
		else
		 return false;
	}
	int getLeftChildIndex(int i)
	{
		return 2 * i + 1;
	}
	int getRightChildIndex(int i)
	{
		return 2 * i + 2;
	}
	void build()
	{	    
	    cout << endl << "Enter root node element : ";
	    cin >> arr[0];

		for(int i = 0 ; hasLeftChild(i) == true && hasRightChild(i) == true ; i++)
		{
			cout << "Enter left child of  " << arr[i] << " node : ";
			cin >> arr[getLeftChildIndex(i)];
			cout << "Enter right child of " << arr[i] << " node : ";
			cin >> arr[getRightChildIndex(i)];
			cout << endl ;
		}
	}
	void display()
	{
		cout << endl << "Array elements are as : ";
		for(int i = 0 ; i < pow(2,height) - 1 ; i++)
		 cout << arr[i] << "[Li=" <<getLeftChildIndex(i) << ",Ri=" << getRightChildIndex(i) << "]  ";
	}
	void preorder(int i)
	{
		cout <<  arr[i] << " ";
		if(hasLeftChild(i))
		 inorder(getLeftChildIndex(i));
		if(hasRightChild(i))
		 inorder(getRightChildIndex(i));
	}
	void inorder(int i)
	{
		if(hasLeftChild(i))
		 inorder(getLeftChildIndex(i));
		cout <<  arr[i] << " ";
		if(hasRightChild(i))
		 inorder(getRightChildIndex(i));
	}
	void postorder(int i)
	{
		if(hasLeftChild(i))
		 inorder(getLeftChildIndex(i));
		if(hasRightChild(i))
		 inorder(getRightChildIndex(i));
		cout <<  arr[i] << " ";
	}
};
int main()
{
	int h;
	
	cout << endl << "Enter height of tree : ";
	cin >> h;
    
    tree t(h);
    t.build();
    t.display();
    cout << endl << "Preorder traversal is as follows : ";
    t.preorder(0);
    cout << endl << "Inorder traversal is as follows : ";
    t.inorder(0);
    cout << endl << "Postorder traversal is as follows : ";
    t.postorder(0);
    return 0;
}
