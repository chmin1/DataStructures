#include<iostream>
using namespace std;

const int MAX = 10; //size of array
int top = -1; // represents top of stack in the array
int Array[MAX]; //array of 10 integers

void push(int); //pushes integers into the stack
void pop();
void Top();
void print();

int main()
{
	int x;
	cout << "Enter Values into the Stack: " << endl;

	for (int i = 0; i < MAX; i++)
	{
		cin >> x;
		push(x);
	}

	pop();
	push(12);
	Top();
	print();

	return 0;
}

void push(int num)
{
	if (top == MAX - 1) // conditional: if MAX is exceeded, The stack is full
	{
		cout << "Error, Stack Overflow" << endl;
		return;
	}

	Array[++top] = num;
}

void pop()
{
	if (top == -1) // conditional// if stack is empty, there is nothing to pop
	{
		cout << "Error: Stack is Empty" << endl;
		return;
	}

	top--;
}

void Top()
{
	cout << "Top of Stack: " << Array[top] << endl;
}

void print()
{
	for (int i = 0; i <= top; i++)
		cout << Array[i] << " ";
	cout << endl;
}