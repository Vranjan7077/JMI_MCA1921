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
protected:
  string name;
  int rollno;
public:
  void get()
  {
    char buffer[255];
    bool isvalid;

    fgets(buffer, sizeof(buffer), stdin);
    do{
       cout << endl << "Enter name of the student : ";
       getline(cin, name);
       isvalid = isValidName(name);
       if(!isvalid) cout << "Invalid Name...! Try Again." << endl;
      }while(!isvalid);


    do{
       cout << "Enter roll number : ";
       cin >> rollno;
       if(rollno < 1)cout << endl << "Invaid Rollno ...! Try Again." << endl;
      }while(rollno < 1);
  }
  void display()
  {
    cout << endl << name << "\t" << rollno;
  }
};

class marks:public student{
protected:
  float marks1,marks2;
public:
  void get_marks()
  {
    do{
       cout << "Enter marks in English (0 <= Marks >= 50) : ";
       cin >> marks1;
       if(marks1 < 0 || marks1 > 50) cout << endl << "Invaid Marks ...! Try Again."<< endl;
      }while(marks1 < 0 || marks1 > 50);
    do{
       cout << "Enter marks in Maths (0 <= Marks >= 50) : ";
       cin >> marks2;
       if(marks2 < 0 || marks2 > 50) cout << endl << "Invaid Marks ...! Try Again." << endl;
      }while(marks2 < 0 || marks2 > 50);
  }
  void display_marks()
  {
   cout << "\t" << marks1 << "\t" << marks2;
  }
};

class result:public marks{
  float total;
public:
  void cal_result()
  {
    total = marks1 + marks2;
  }
  void display_result()
  {
   if(total >= PASS_MARKS)
    cout << "\t" << "Passed";
   else
    cout << "\t" << "Failed";
  }
};

int main()
{
  int n;

  do{
     cout << endl << "How many students : ";
     cin >> n;

     if(n < 1) cout << endl << "Invalid input...! Try again.";
   }while(n < 1);

  result s[n];

  for(int i = 0 ; i < n ; i++)
  {
   s[i].get();
   s[i].get_marks();
   s[i].cal_result();
  }

  cout << endl << "Name\tRollno\tEnglish\tMaths\tResult"<< endl;
  for(int i = 0 ; i < 38 ; i++ , cout << "-");
  for(int i = 0 ; i < n ; i++)
  {
    cout << endl;
    s[i].display();
    s[i].display_marks();
    s[i].display_result();
  }
}
