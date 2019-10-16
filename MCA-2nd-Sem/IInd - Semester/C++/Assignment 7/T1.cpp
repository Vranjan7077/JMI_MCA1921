#include<iostream>
using namespace std;
template <class t>
void bubble(t a[],int n)
{
	int temp;
	for(int i=0;i<n-1;i++ ){
	
	      for(int j=0;j<n-1-i;j++)
	            {
				if(a[j]>a[j+1])
	            {temp=a[j];
	            a[j]=a[j+1];
	            a[j+1]=temp;
				}
			}
			
		}
}
int main()
{
     system("cls");
	int a[5]={10,3,5,20,1};
	 bubble(a,5);
	 for(int i=0;i<5;i++ )
{
	 	 cout<<a[i];
}	 return 0;
}
