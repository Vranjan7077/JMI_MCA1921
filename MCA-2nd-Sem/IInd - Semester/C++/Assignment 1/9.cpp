#include<iostream>
using namespace std;
class vector;
class matrix
{
	private:
	        int mt[3][3];
	public:
		    void getmatrix()
		{
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					cin>>mt[i][j];
				}
			}
			return;
		}
		void dismatrix()
		{
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					cout<<mt[i][j]<<"   ";
				}
				cout<<endl;
			}
			return;
		}
		friend vector multiply(vector &,matrix &);
};

class vector
{
	int vt[3];
	public:
	void getvector()
		{
			for(int i=0;i<3;i++)
			{
				cin>>vt[i];
			}
			return;
		}
	void disvector()
		{
			for(int i=0;i<3;i++)
			{
				cout<<vt[i]<<"   ";
			}
			return;	
		}
		friend vector multiply(vector&,matrix&);
};
vector multiply(vector &v,matrix &m)
{
	vector temp;
	for(int i=0;i<3;i++)
	{
		temp.vt[i]=0;
		for(int j=0;j<3;j++)
		{
			temp.vt[i]+=v.vt[j]*m.mt[i][j];
		}
	}
	cout<<"\n\nResultant vector is:\n";
	return temp;
}
int main()
{
	matrix m1;
	vector v1,v;
	cout<<"\nEnter the Elements of 3X3 Matrix: \n";
	m1.getmatrix();
	cout<<endl<<"Enter a vector: \n";
	v1.getvector();
	cout<<endl<<"Entered Matrix Is: \n";
	m1.dismatrix();
	cout<<endl<<"Entered vector Is: \n";
	v1.disvector();
	v=multiply(v1,m1);
	v.disvector();
	return 0;
}
