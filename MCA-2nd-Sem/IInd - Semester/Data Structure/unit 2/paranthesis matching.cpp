//parenthesis_matching on 19-03-19
//
//Program to Check for balanced parenthesis in an expression
//

#include<iostream>

using namespace std;
class ParenthesisMatching{
  string str;
public:
  friend istream& operator >>(istream&,ParenthesisMatching&);
  friend ostream& operator <<(ostream&,ParenthesisMatching&);
  bool CheckIsBalanced();
};

  istream& operator >>(istream& input, ParenthesisMatching& p)
  {
    cout << endl << "Enter expression [HINT : use '(' / ')']: ";
    getline(cin, p.str);
  }

  ostream& operator <<(ostream& output, ParenthesisMatching& p)
  {
    cout << endl << "Expression is : ";
    output << p.str;
  }

  bool ParenthesisMatching::CheckIsBalanced()
  {
    char stack[str.length()-1];
    int tos = -1;
    int isbalanced = 1;
    int i;

    for(i = 0 ; i < str.length() ; i++)
    {
      if( str[i] == '(')
       stack[++tos] = str[i];
      else if( str[i] == ')' )
      {
        if(tos == -1)    //means ')' is the first instance among parenthesis or after some balanced parenthesis
        {                // eg 1+2)+3+3----
          isbalanced = 0;//eg (1+(2+(3+4)+5)+6)+7)+----here after 7 when reading ')' makes it unbalanced by checking value of tos = -1
          break;
        }
        if(stack[tos] == '(')
         tos--;
       }
     }
  if(tos >= 0 || isbalanced == 0)
     return false;
    else
     return true;
   }

int main()
{
  ParenthesisMatching expression;

   cin >> expression;
   cout << expression;

   if(expression.CheckIsBalanced())
    cout << endl << "Balanced Parenthesis.";
   else
    cout << endl << "Unbalanced Parenthesis...!";

  return 0;
}
