/
//
//
//
#include<iostream>

using namespace std;

void sort(int array[], int n)
{
  int i, j, minIndex, temp;
  
  for(i = 0 ; i < n - 1 ; i++)
  {
    minIndex = i;
    for(j = i + 1 ; j < n ; j++)
    {
       if(array[j] < array[minIndex])
         minIndex = j;
    }
    temp = array[i];
    array[i] = array[minIndex];
    array[minIndex] = temp;
  }
}
int main()
{
    int n, i;
    
    cout << endl << "Enter no of elements : ";
    cin >> n;
    
    int array[n];    
    
    cout << endl << "You have to enter " << n << " elements : " << endl;
    for(i = 0 ; i < n ; i++ )
      cout << "Array[" << i + 1 << "] : ", cin >> array[i];

    cout << endl << "Array before sorting : ";
    for(i = 0 ; i < n ; i++ ) cout << array[i] << " ";
    sort(array, n);
    cout << endl << "Array after sorting  : ";
    for(i = 0 ; i < n ; i++ ) cout << array[i] << " ";

    return 0;
}
