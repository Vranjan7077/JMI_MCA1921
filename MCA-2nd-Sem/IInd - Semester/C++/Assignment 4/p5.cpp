#include<iostream>
#include<stdio.h>

using namespace std;
bool isValidName(string name)
{
   for(int i = 0 ; i < name.length() ; i++)
   { 
     if((name[i] < 65 || name[i] > 90) && (name[i] < 97 || name[i] > 122) && name[i] != 32)  //ascii code of space is 32
     return false;
   }
  return true;
}
class user
{
    string name;
    int age;
public:
    user(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
  public:
    void putdata()
    {
      cout << endl << "Name = " << name << endl << "Age = " << age;
    }
};

class student:public user{
    string course;
    int rollno;
    float m1, m2, m3;
public:
    student(string name, int age):user(name, age){} // calling base class constructor

    void getdata()
    {
        bool isvalid;
        char buffer[255];
        fgets(buffer, sizeof(buffer), stdin);
        do
		{
           cout << endl << "Enter course name : ";
           cin >> course;
           isvalid = isValidName(course);
           if(!isvalid) cout << "Invalid  Course Name...! Try Again." << endl;
          }while(!isvalid);

        do{  
           cout << endl << "Enter roll no : ";
           cin >> rollno;
           if(rollno < 1) cout << "Invalid rollno...! Try Again." << endl;          
          }while(rollno < 1);
        
        do{
           cout << endl << "Enter marks1 : ";
           cin >> m1;
           if(m1 < 0 || m1 > 100) cout << "Invalid marks...! Try Again." << endl;
          }while(m1 < 0 || m1 > 100);
        
        do{
           cout << endl << "Enter marks2 : ";
           cin >> m2;
           if(m2 < 0 || m2 > 100) cout << "Invalid marks...! Try Again." << endl;
          }while(m2 < 0 || m2 > 100);
        
        do{
           cout << endl << "Enter marks3 : ";
           cin >> m3;
           if(m3 < 0 || m3 > 100) cout << "Invalid marks...! Try Again." << endl;
          }while(m3 < 0 || m3 > 100);
    }
     void putdata()
     {
         float total;
         cout << endl << "Rollno = " << rollno << endl << "Course = " << course;
         total = m1 + m2 + m3;
         cout << endl << "M1 = " << m1
              << endl << "M2 = " << m2
              << endl << "M3 = " << m3
              << endl << "Total = " << total;
     }
};

class teacher:public user{
    string subject_assigned;
    string contact_hour;
public:
    teacher(string name, int age):user(name, age){} // calling base class constructor

    void getdata()
    {
        char buffer[255];
        cout << endl << "Enter subject assigned to teacher : ";
        fgets(buffer, sizeof(buffer), stdin);
        getline(cin , subject_assigned);

        cout << endl << "Enter contact hour of teacher : ";
        getline(cin , contact_hour);
    }

     void putdata()
     {
         cout << endl << "Subject assigned = " << subject_assigned;
         cout << endl << "Contact hour = " << contact_hour;
     }
};

int main()
{
  string name;
  int age;
  char buffer[255];
  bool isvalid;
  do{
     cout << endl << "Enter name of Student : ";
     getline(cin , name);
     isvalid = isValidName(name);
     if(!isvalid) cout << "Invalid Name...! Try Again." << endl;
    }while(!isvalid);

  do{ 
     cout << endl << "Enter age of Student : ";
     cin >> age;
     if(age < 1) cout << "Invalid input...! Try Again." << endl;
    }while(age < 1);

  student s( name, age);
  s.getdata();

  fgets(buffer, sizeof(buffer), stdin);
  do{
     cout << endl << "Enter name of Teacher : ";
     getline(cin , name);
     isvalid = isValidName(name);
     if(!isvalid) cout << "Invalid Name...! Try Again." << endl; 
    }while(!isvalid);

  do{
     cout << endl << "Enter age of Teacher : ";
     cin >> age;
     if(age < 1) cout << "Invalid input...! Try Again." << endl;
    }while(age < 1);

  teacher t(name, age);
  t.getdata();

  cout << endl << endl << "Student details are as  : " << endl;
  s.user::putdata();
  s.putdata();

  cout << endl << endl << "Teacher details are as  : " << endl;
  t.user::putdata();
  t.putdata();

  return 0;
}
