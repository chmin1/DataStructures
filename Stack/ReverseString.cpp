#include<iostream>
#include<stack> //stack from standard template library (STL)
using namespace std;

class Stack // defines stack as a class structure
{
private: // private = only accessible through the "stack" type
	char Array[101]; //character array
	int top; //marks the top of the stack in the array
public:
	void Push(int);
	void Pop();
	int Top();
	bool isEmpty();
};
void Reverse(char[], int);

int main()
{
	char string[51];
	cout << "Enter a String: " << endl;
	gets_s(string);
	Reverse(string, strlen(string));
	cout << "Output: " << string << endl;
	return 0;
}

void Reverse(char *C, int num)
{
	stack<char> S; //creates a stack of Character values
	for (int i = 0; i < num; i++)
	{
		S.push(C[i]); // pushes the array to stack
	}

	for (int i = 0; i < num; i++)
	{
		C[i] = S.top(); // character at space "i" is overwritten
		S.pop(); //pop character
	}

}