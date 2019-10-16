//
//
//
//
#include<iostream>
using namespace std; // CTM: Elements of both the array must be in sorted order so to merge them in third one.

void sort(int arrayA[], int n1, int arrayB[], int n2, int arrayC[])
{
  int i, j, k;
  i = j = k = 0;

  while(i < n1 && j < n2)
    if( arrayA[i] < arrayB[j] )
     arrayC[k++] = arrayA[i++];
    else 
     arrayC[k++] = arrayB[j++];

  while(i<n1) arrayC[k++] = arrayA[i++];
  while(j<n2) arrayC[k++] = arrayB[j++];
  
// or use below code snippet
/*
while(i < n1 && j < n2)
{
    if( arrayA[i] < arrayB[j] )
    {
      arrayC[k] = arrayA[i];
      i++;
    }
    else
    {
      arrayC[k] = arrayB[j];
      j++;
    }
    k++;
}
  while(i<n1)
  {
      arrayC[k] = arrayA[i];   
      k++;
      i++;
  }
  while(j<n2)
  {
      arrayC[k] = arrayB[j];
      k++;
      j++;
  }
*/
}

int main()
{
    int n1, n2, n3, i;
    
    cout << endl << "Enter no of elements of array 'A' : ";
    cin >> n1;
    cout << endl << "Enter no of elements of array 'B' : ";
    cin >> n2;
    
    int arrayA[n1];    
    int arrayB[n2];
    n3 = n1 + n2;
    int arrayC[n3];    
    
    cout << endl << "You have to enter " << n1 << " elements for array 'A' : " << endl;
    for(i = 0 ; i < n1 ; i++ )
      cout << "Array[" << i + 1 << "] : ", cin >> arrayA[i];

    cout << endl << "You have to enter " << n2 << " elements for array 'B' : " << endl;
    for(i = 0 ; i < n2 ; i++ )
      cout << "Array[" << i + 1 << "] : ", cin >> arrayB[i];


    cout << endl << "Array 'A' : ";
    for(i = 0 ; i < n1 ; i++ ) cout << arrayA[i] << " ";

    cout << endl << "Array 'B' : ";
    for(i = 0 ; i < n2 ; i++ ) cout << arrayB[i] << " ";

    sort(arrayA, n1, arrayB, n2, arrayC);
    cout << endl << "Array 'C' : ";
    for(i = 0 ; i < n1 + n2 ; i++ ) cout << arrayC[i] << " ";
    return 0;
}
