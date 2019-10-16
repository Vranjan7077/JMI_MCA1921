#include<iostream>
using namespace std;

class base{
  int x;
  friend class derived;
  public:
  int y;
  void getdata()
  {
   cout << endl << "Enter value of x : ";
   cin >> x;
   cout << "Enter value of y : ";
   cin >> y;
  }
  void putdata()
  {
   cout << endl << "x = " << x << "\tY = " << y;
  }

};

class derived:private base{
  int d;
public:
  class base b;
  void getdata();
  void putdata();
};
void derived::getdata()
{
  b.base::getdata();    // CTM: we can access base class data members in this function as well without calling its functions like 'b.x'
  cout << "Enter value of d : ";
  cin >> d;
}

void derived::putdata()
{
   b.base::putdata();
  cout << endl << "D = " << d;
}

int main()
{
  derived obj;

  obj.getdata();
  obj.putdata();

  return 0;
}
