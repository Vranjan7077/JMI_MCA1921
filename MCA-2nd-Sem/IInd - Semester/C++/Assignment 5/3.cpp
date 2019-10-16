#include<iostream>

using namespace std;



class shape{
public:
 virtual void area(){};
 virtual void display(){};
};




class circle:public shape
  {
  double radius;
  public:
  void getdata()
   {
    cout << "\nEnter radius of circle : ";
    cin >> radius;
    }

  void display()
   {
    cout << "\n\nShape : Circle" << "\nRadius: " << radius;
    }

  void area()
   {
    cout << "\nArea  : " << 3.14159 * radius * radius;
      }
   
};






class rectangle:public shape
 {
  double width, length;
  public:
  void getdata()
   {
    cout <<"\nEnter width of Rectangle : ";
    cin >> width;
    cout << "\nEnter lenght of Rectangle : ";
    cin >> length;
      }

  void display()
   {
    cout <<"\n\nShape : Rectangle" <<"\nWidth : " << width <<"\nLenght: " << length;
      }

  void area()
   {
   cout <<"\nArea  : " << width * length;
   }  
};





class trapezoid:public shape
{
 double base1, base2, height;
 public:
 void getdata()
   {
    cout <<"\nEnter trapezoid base 1 : ";
    cin >> base1;
    cout << "\nEnter trapezoid base 2 : ";
    cin >> base2;
    cout << "\nEnter height : ";
    cin >> height;
    }

 void display()
   {
    cout <<"\n\nShape : Trapezoid" << "\nBase1 : " << base1 <<"\nBase2 : " << base2 <<"\nHeight: "<<height;
  }

 void area()
   {
    cout <<"\nArea  : " << ((base1 + base2) / 2) * height<<endl;
   }
  
};






int main()
{
    shape* p;
    circle c;
    rectangle r;
    trapezoid t;

    p = &c;
    c.getdata();
    p = &r;
    r.getdata();
    p = &t;
    t.getdata();

    p = &c;
    p->display();
    p->area();
    
    p = &r;
    p->display();
    p->area();
    
    p = &t;
    p->display();
    p->area();
    
    return 0;
}
