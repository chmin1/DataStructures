/*This program will check for the balancing of Parenthesis/brackets/curly braces.
  What to check for:
  1. number of opening parenthesis = number of closing parenthesis
  2. Every opening must find a closing to its right & every closing must find a opening to its left
  3. a parenthesis can closeonly AFTER all other Parenthesis opened inside of it are closed
     or LAST OPENED FIRST CLOSED*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

//This function checks whether 2 characters are opening and closing of the same type
bool ArePair(char opening, char closing)
{
	if (opening == '(' && closing == ')') 
		return true;
	else if (opening == '{' && closing == '}') 
		return true;
	else if (opening == '[' && closing == ']') 
		return true;
	
	return false;
}

void CheckBalancedParenthesis(string str)
{
	int n = str.length(); //stores length of the string
	stack<char> S; // creates a stack for character values
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			S.push(str[i]); //if there is an opening, push the character to stack
		}
		else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
		{
			if (S.empty() || ArePair(S.top(), str[i]) == false) // if the stack  is empty, or the parenthesis aren't the same type
			{
				cout << "Expression is Not Balanced." << endl;
				return;
			}
			else // if the stack is not empty and the parenthesis are the same type
				S.pop();
		}
	}

	if (S.empty()) // if the stack is empty, expression is balanced
		cout << "Expression is Balanced" << endl;

}

int main()
{
	string exp;
	cout << "Enter an expression:  ";
	cin >> exp;
	CheckBalancedParenthesis(exp);

	return 0;
}