#include<iostream>
using namespace std;
class polygon
{
    protected:
    double width, height;
    public:
      void set_value()
       {
       cout << "\nEnter width : ";
        cin >> width;
       cout << "Enter height : ";
        cin >> height;
       }
};
class rectangle: public polygon
{
    public:
    double calculate_area();
};
double rectangle::calculate_area()
   {
      return (width * height);        
   }

class triangle: public polygon
{
    public:
    double calculate_area();
};
double triangle::calculate_area()
   {
     return ((width * height) / 2 );  
   }
int main()
{
    polygon *p;
    rectangle r;
    triangle t;
    p = &r;
    p->set_value();
    cout << "Area of Rectangle is : " << r.calculate_area() << endl;
    p = &t;
    p->set_value();
    cout << "Area of triangle is :  " << t.calculate_area() << endl;
    return 0;
}
