//
//
//
//
#include<iostream>
using namespace std; // CTM: Elements of both the array must be in sorted order so to merge them in third one.

void sort(int arrayAB[], int mid, int high, int arrayC[])
{
  int i, j, k ;
  i = k = 0;
  j = mid + 1;

  while(i <= mid && j <= high)
    if(arrayAB[i] < arrayAB[j])
      arrayC[k++] = arrayAB[i++];
    else
      arrayC[k++] = arrayAB[j++];

  while(i <= mid)  arrayC[k++] = arrayAB[i++];
  while(j <= high) arrayC[k++] = arrayAB[j++];
}
int main()
{
    int n1, n2, n3, i;
    
    cout << endl << "Enter no of elements of array 'A' : ";
    cin >> n1;
    cout << endl << "Enter no of elements of array 'B' : ";
    cin >> n2;

    int length = n1 + n2;
    int arrayAB[length];    
    int arrayC[length];    

    int mid, high;

    mid = n1-1;
    high  = mid + n2;

    cout << endl << "You have to enter " << n1 << " elements for array 'A' : " << endl;
    for(i = 0 ; i <= mid ; i++ )
    {
      cout << "ArrayAB[" << i + 1 << "] : ";
      cin >> arrayAB[i];
    }
    
    cout << endl << "You have to enter " << n2 << " elements for array 'B' : " << endl;

    for(i =  mid + 1 ; i <= high ; i++)    
    {
      cout << "ArrayAB[" << i + 1 << "] : ";
      cin >> arrayAB[i];
    }
    
    cout << endl << "Array 'A' : ";
    for(i = 0 ; i <= mid ; i++ ) cout << arrayAB[i] << " ";

    cout << endl << "Array 'B' : ";
    for(i = mid + 1 ; i <= high ; i++ ) cout << arrayAB[i] << " ";
     
    sort(arrayAB, mid, high, arrayC);

    cout << endl << "Sorted Array are as : ";
    for(i = 0 ; i <= high ; i++) cout << arrayC[i] << "  ";
  
    return 0;
}
