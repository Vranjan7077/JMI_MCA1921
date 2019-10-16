#include<iostream>
#include<stdio.h>
using namespace std;
class staff
{
protected:
  string name;
  int code;

public:
  void getdata()
  {
    bool isvalid;
    do
	{
       cout << endl << "Enter staff name : ";
       getline(cin ,name);
       isvalid = isValidName(name);
       if(!isvalid) cout << "Invalid Name...! Try Again." << endl << endl;
      }
	  while(!isvalid);
      
    do
	{
       cout << "Enter staff Code : ";
       cin >> code;
       if(code < 1) cout << "Invalid input...! Try Again." << endl << endl;
      }
	  while(code < 1);

  }

  void putdata()
  {
    cout << endl << "Staff Name = " << name << endl << "Staff Code = " << code;
  }
};

class faculty:public staff{
  string department;
  string subject_taken;
  string research_area;
public:
  void getdata()
  {
    bool isvalid;
    char buffer[255];
    fgets(buffer,sizeof(buffer), stdin);
   
    do{
       cout << "Enter dept. name : ";
       getline(cin, department); 
       isvalid = isValidName(department);
       if(!isvalid) cout << "Invalid input...! Try Again." << endl << endl;
      }while(!isvalid);
    
    do{
       cout << "Enter subject taken : ";
       getline(cin, subject_taken);
       isvalid = isValidName(subject_taken);
       if(!isvalid) cout << "Invalid input...! Try Again." << endl << endl;
      }while(!isvalid);
    
    do{
       cout << "Enter research area : ";
       getline(cin, research_area);
       isvalid = isValidName(research_area);
       if(!isvalid) cout << "Invalid input...! Try Again." << endl << endl;
      }while(!isvalid);
  }
  void putdata()
  {
    cout << endl << "Dept.  = " << department << endl << "Subject  = " << subject_taken << endl << "Research area = " << research_area;
  }
};

class typist:public staff{
  protected:
  string office;
  int speed;
public:
  void getdata()
  {
    bool isvalid;
    char buffer[255];
    fgets(buffer,sizeof(buffer), stdin);

    do{
       cout << "Enter Typist office : ";
       getline(cin, office);
       isvalid = isValidName(office);
       if(!isvalid) cout << "Invalid input...! Try Again." << endl << endl;
      }while(!isvalid);
    

    do{
       cout << "Enter Typing speed : ";
       cin >> speed;
       if(speed < 1) cout << "Invalid Input...! Try Again." << endl << endl;
      }while(speed  < 1);
  }
  void putdata()
  {
    cout << endl << "Typist Office = " << office << endl << "Typing speed = " << speed << "wpm";
  }
};

class officer:public staff{
  string rank;
  char grade;
public:
  void getdata()
  {
    bool isvalid;
    char buffer[255];
    fgets(buffer,sizeof(buffer), stdin);
    
    do{
       cout << "Enter Officer rank : ";
       getline(cin, rank);
       isvalid = isValidName(rank);
       if(!isvalid) cout << "Invalid input...! Try Again." << endl << endl;
      }while(!isvalid);
    
    do{
       cout << "Enter grade : ";
       cin >> grade;
       isvalid = isValidChar(grade);
       if(!isvalid) cout << "Invalid input...! Try Again." << endl << endl;
      }while(!isvalid); 
  }
  void putdata()
  {
    cout << endl << "Officer rank = " << rank << endl << "Grade = " << grade;
  }
};

class permanent:public typist{
  long int salary;
public:
  void getdata()
  {
    char buffer[255];
    do{
       cout << "Enter salary ( S > 1000 ) : ";
       cin >> salary;
       if(salary < 1000) cout << "Invalid input...! Try Again." << endl << endl;
      }while(salary < 1000);

    fgets(buffer,sizeof(buffer), stdin);
  }
  void putdata()
  {
    cout << endl << "Salary = " << salary;
  }
};

class casual:public typist{
  long int salary;
public:
  void getdata()
  {
    char buffer[255];
    do{
       cout << "Enter salary ( S > 1000 ): ";
       cin >> salary;
       if(salary < 1000) cout << "Invalid input...! Try Again." << endl << endl;
      }while(salary < 1000);
    
    fgets(buffer,sizeof(buffer), stdin);
  }
  void putdata()
  {
    cout << endl << "Salary = " << salary;
  }
};

int main()
{

  faculty obj_faculty;
  permanent obj_permanent_typist;
  casual obj_casual_typist;
  officer obj_officer;

  cout << endl << "Enter faculty Details : ";
  obj_faculty.staff::getdata();
  obj_faculty.getdata();

  cout << endl << "Enter permanent Typist Details : ";
  obj_permanent_typist.staff::getdata();
  obj_permanent_typist.typist::getdata();
  obj_permanent_typist.getdata();

  cout << endl << "Enter casual Typist Details : ";
  obj_casual_typist.staff::getdata();
  obj_casual_typist.typist::getdata();
  obj_casual_typist.getdata();

  cout << endl << "Enter Officer Details : ";
  obj_officer.staff::getdata();
  obj_officer.getdata();


  cout << endl << endl << endl << "Faculty Details : ";
  obj_faculty.staff::putdata();
  obj_faculty.putdata();

  cout << endl << endl << "Permanent Typist Details : ";
  obj_permanent_typist.staff::putdata();
  obj_permanent_typist.typist::putdata();
  obj_permanent_typist.putdata();

  cout << endl << endl << "Casual Typist Details : ";
  obj_casual_typist.staff::putdata();
  obj_casual_typist.typist::putdata();
  obj_casual_typist.putdata();

  cout << endl << endl << "Officer Details : ";
  obj_officer.staff::putdata();
  obj_officer.putdata();

  return 0;
}
