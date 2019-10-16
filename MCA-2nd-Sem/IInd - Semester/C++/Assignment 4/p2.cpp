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

class student{
    string name, course;
    int rollno;
    public:
    void input_student();
    void display_student();
    string getname(){ return name; }
};

class exam:private student{
    float marks1, marks2, marks3;
    public:
    void input_marks();
    void display_marks();
};

void student::input_student()
{
  char buffer[255];
  bool isvalid;
  fgets(buffer, sizeof(buffer), stdin); // clearing standard input stream
    do{
       cout << endl << "Enter name of student : ";
       getline(cin, name);
       isvalid=isValidName(name);
       if(!isvalid) cout << "Invalid Name...! Try Again." << endl;
     }while(!isvalid);

    do{
       cout << "Enter " << name << "'s rollno : ";
       cin >> rollno;
       if(rollno < 1) cout << "Invalid input...! Try again" << endl;
    }while(rollno < 1);
    
      fgets(buffer, sizeof(buffer), stdin); // clearing standard input stream
    do{ 
       cout << "Enter " << name << "'s course : ";
       getline(cin, course);
       isvalid = isValidName(course);
       if(!isvalid) cout << "Invalid Name...! Try Again." << endl;
     }while(!isvalid);

}

void student::display_student()
{
  cout << endl << "Name = " << name
       << endl << "Roll no = " << rollno
       << endl << "Course = " << course;
}

void exam::input_marks()
{
  input_student();
  do{
     cout << "Enter " << getname() << "'s marks in History ( 0 <= M <= 100 ): ";
     cin >> marks1;
     if(marks1 < 0 || marks1 > 100) cout << "Invalid input...! Try again" << endl;
    }while(marks1 < 0 || marks1 > 100);

  do{
     cout << "Enter " << getname() << "'s marks in Political Science ( 0 <= M <= 100 ): ";
     cin >> marks2;
     if(marks2 < 0 || marks2 > 100) cout << "Invalid input...! Try again" << endl;
    }while(marks2 < 0 || marks2 > 100);

  do{
     cout << "Enter " << getname() << "'s marks in Urdu  ( 0 <= M <= 100 ): ";
     cin >> marks3;
     if(marks3 < 0 || marks3 > 100) cout << "Invalid input...! Try again" << endl;
    }while(marks3 < 0 || marks3 > 100);
}

void exam::display_marks()
{
    display_student();
    cout << endl << "History Marks : " << marks1
         << endl << "Political Science Marks : " << marks2
         << endl << "Urdu marks : " << marks3;
}

int main()
{
    int n;
    do{
       cout << endl << "Enter no. of students : ";
       cin >> n;
       if( n < 1) cout << "Invalid input...! Try again." << endl;
    }while(n < 1);

    exam s[n];
    for( int i = 0 ; i < n ; i++ )
    {
        s[i].input_marks();
        cout << endl;
    }
    cout << endl << "Student Details :";

    for( int i = 0 ; i < n ; i++ )
    {
        s[i].display_marks();
        cout << endl;
    }
    return 0;
}
