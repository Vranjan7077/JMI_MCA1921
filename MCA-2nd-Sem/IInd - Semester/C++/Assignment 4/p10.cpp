#include<iostream>
#include<stdio.h>

using namespace std;

class university{
  string name, dept, person;
public:
  void display();
  void getdata();
};

class company{
  string name;
  int no_of_engineers;
  long int amount_invested;
public:
  void display();
  void getdata();
};

class project:public university, public company{
  string type;
  int duration;
  long int amount_granted;

public:
  void display();
  void getdata();
};

void university::getdata()
{
  bool isvalid;
  do{
     cout << endl << "Enter University Name : ";
     getline(cin, name);
     isvalid = isValidName(name);
     if(!isvalid) cout << "Invalid Name...! Try Again." << endl << endl;
    }while(!isvalid);
  
  do{
     cout << "Enter Dept. name : ";
     getline(cin, dept);
     isvalid = isValidName(dept);
     if(!isvalid) cout << "Invalid Name...! Try Again." << endl << endl;
    }while(!isvalid);
 
  do{
     cout << "Enter name of person to whome project is assigned : ";
     getline(cin, person);
     isvalid = isValidName(person);
     if(!isvalid) cout << "Invalid Name...! Try Again." << endl << endl;
    }while(!isvalid);
}

void university::display()
{
  cout << endl <<"University : " << name << endl << "Dept. : " << dept << endl << "Project Assigned to : " << person;
}
void company::getdata()
{
  bool isvalid;
  do{
     cout << "Enter name of Company : ";
     getline(cin, name);
     isvalid = isValidName(name);
     if(!isvalid) cout << "Invalid Name...! Try Again." << endl << endl;
    }while(!isvalid);

  do{
     cout << "Enter no. of Engineers working on project : ";
     cin >> no_of_engineers;
     if(no_of_engineers < 1) cout << "Invalid input...! Try Again." << endl << endl;
    }while(no_of_engineers < 1);
  
  do{
     cout << "Enter amount invested yet on project : ";
     cin >> amount_invested;
     if(amount_invested < 1) cout << "Invalid input...! Try Again." << endl << endl;
    }while(amount_invested < 1);
  
}
void company::display()
{
  cout << endl << "Company : " << name << endl << "Total no of Engineers : " << no_of_engineers << endl << "Amount Granted : " << amount_invested;
}

void project::getdata()
{
  char buffer[255];

  cout << "Enter Type of Project : ";
  fgets(buffer, sizeof(buffer), stdin);
  getline(cin, type);

  do{
     cout << "Enter duration of projects in years : ";
     cin >> duration;
     if(duration < 1) cout << "Invalid input...! Try Again." << endl << endl;
    }while(duration < 1);
  
  do{
     cout << "Enter amount granted : ";
     cin >> amount_granted;
     if(amount_granted < 1) cout << "Invalid input...! Try Again." << endl << endl;
    }while(amount_granted < 1);

}
void project::display()
{
  cout << endl << "Project type : " << type << endl << "Duration : " << duration << " yrs." << endl << "Amount Granted : " << amount_granted;
}
  int main()
  {
    project p;

    p.university::getdata();
    p.company::getdata();
    p.getdata();

    cout << endl << "Project details are as : " << endl;
    p.university::display();
    p.company::display();
    p.display();

    return 0;
  }
