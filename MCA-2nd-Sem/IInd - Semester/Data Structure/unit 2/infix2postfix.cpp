//infixtopostfix.cpp on 21-03-19
//
//Program to implement convert infix expression to postfix expression
//
#include <bits/stdc++.h>

using namespace std;

class INFIX{
  string infix, postfix; // used to store infix and postfix expressions
  string stack;

  bool isoperator(char);
  int priority(char);
  void push(char);
  void pop();
  char top();
public:
 friend istream& operator >> (istream&, INFIX&);
 friend ostream& operator << (ostream&, INFIX&);
 void convet_to_postfix();
};

istream& operator >> (istream& input, INFIX& e)
{
  cout << endl << "Enter infix expression : ";
  getline(cin,e.infix);
}

ostream& operator << (ostream& out, INFIX& e)
{
  out << endl << "Infix expression  =  " << e.infix;
  out << endl << "Postfix expression  =  " << e.postfix;
}

void INFIX::convet_to_postfix()
{
  postfix ="";
  for(int i = 0 ; i < infix.length() ; i++)
  {
    if((infix[i] >= 48 && infix[i] <= 57) || (infix[i] >= 65 && infix[i] <= 90) || (infix[i] >= 97 && infix[i] <= 122) )// for 0-9 or A-Z or a-z
     postfix.push_back(infix[i]);
    else
    {
        if(infix[i] == '(')
        {
          push(infix[i]);
        }
        else if(infix[i] == ')')
        {
             while(top() != '(')
             {
               postfix +=top();
               pop();
             }
         pop(); // removing '('
        }
        else if(isoperator(infix[i]))
        {
              if( stack.length() == 0 || top() == '(')
                push(infix[i]);
              else if(priority(infix[i]) > priority(top()))//stack may be empty then how to get  'priority(top())'
                push(infix[i]);                                        // so its better to write it seperately after verifying stack in not empty
              else
              {
                    while(stack.length() > 0 && priority(infix[i]) <= priority(top()) )
                    {
                      postfix += top();
                      pop();
                    }
                    push(infix[i]);
              }
        }
      }
  }
  if(stack.length() > 0)
    for( int i = stack.length() - 1 ; i >= 0 ; i--)
       postfix += stack[i];
}

bool INFIX::isoperator(char c)
{
  if(c == '^' || c == '/' || c == '*' || c == '+' || c == '-')
  return true;
  else
  return false;
}

int INFIX::priority(char op)
{
  switch(op)
  {
    case '^' : return 3; break;
    case '*' : return 2; break;
    case '/' : return 2; break;
    case '+' : return 1; break;
    case '-' : return 1; break;
  }
}

void INFIX::push(char ch)
{
  stack.push_back(ch);
}

void INFIX::pop()
{
  // its better to create own pop function rather than using pop_back() as it working only in C++11
  if(stack.length() > 0)
   stack.resize(stack.length() - 1);
}

char INFIX::top()
{
  return stack[stack.length()-1];
}

int main()
{
  INFIX exp;
  char choice;
  char buffer[255];

  do{
     cin >> exp;
     exp.convet_to_postfix();
     cout << exp;

     cout << endl << "Do you want to continue y/n : ";
     cin >> choice;
     fgets(buffer, sizeof(buffer), stdin);

   }while(choice == 'y' || choice == 'Y');

  return 0;
}
