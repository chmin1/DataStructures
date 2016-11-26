#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* top = NULL; //head node; empty stack
void Push(int); // Pushes a node into the Stack/List
int Pop(); //takes the top node out of the stack/list
bool isEmpty(); //checks if stack is empty
int TopStack(); //return very top value of Stack
void print();
void clear();

int main()
{
	int amount, case_choice, val;
	char again;

	cout << "How Many Numbers would you like to add: ";
	cin >> amount;

	for (int i = 0; i < amount; i++)
	{
		cout << "Enter a integer: ";
		cin >> val;

		Push(val);
	}
	print();

	cout << "What would you Like to do now?" << endl;

	do
	{
		cout << "1. Push to Stack" << endl
			<< "2. Pop from Stack" << endl
			<< "3. Check if Stack is Empty" << endl
			<< "4. Peek at Top Value" << endl
			<< "5. Clear Stack" << endl
			<< "6. Quit." << endl
			<< "Please make a choice (1-6): ";
		cin >> case_choice;
		while (case_choice < 1 || case_choice > 6)
		{
			cout << "invalid choice, Try again" << endl;
			cin >> case_choice;
		}

		switch (case_choice)
		{
		case 1:
			cout << "How Many values would you like to add: ";
			cin >> amount;
			for (int x = 0; x < amount; x++)
			{
				cout << "Enter value: ";
				cin >> val;
				Push(val);
			}
			print();
			break;
		case 2:
			cout << "Popping top value from stack..." << endl;
			if (top == NULL)
			{
				cout << "Stack is Empty" << endl;
				break;
			}
			else
			{
				cout << "The value popped from stack: " << Pop() << endl;
				print();
				break;
			}
		case 3:
			if (isEmpty() == true)
				cout << "The Stack is Empty" << endl;
			else
				cout << "Stack is not empty" << endl;
			break;
		case 4:
			if (top == NULL)
			{
				cout << "Stack is Empty" << endl;
				break;
			}
			else
			{
				cout << "The Value at the top of your stack: " << TopStack() << endl;
				break;
			}
		case 5:
			clear();
			break;
		case 6:
			break;
		}

		cout << "Would you like to try something else? (Y/N)" << endl;
		cin >> again;
	} while (again == 'Y' || again == 'y');

	cout << endl;

	return 0;
}

void Push(int num)
{
	node* temp = new node(); // creates new node
	temp->data = num;// data field of node is filled
	temp->next = top; // node now points to what head node points to
	top = temp; // Node is now at the top of the list/stack
}

int Pop()
{
	node* temp; //creates pointer node
	int x;
	temp = top; // temp points to the top of the stack/list
	top = temp->next; //head node now points to the node after temp/2nd node
	x = temp->data;
	delete(temp); //deletes node from list/pops node from stack

	return x;
}

bool isEmpty()
{
	if (top == NULL)
		return true;
	else
		return false;
}

int TopStack()
{
	int x;
	node* temp; // creates pointer node
	temp = top; // temp points to the top of the List
	x = temp->data; // stores value on top of stack
	return x;
}

void clear()
{
	node* temp;
	if (top == NULL) //conditional: if list is empty, there is nothing to print
	{
		cout << "The Stack is Already Empty." << endl;
		return;
	}

	else
	{
		while (top != NULL)
		{
			temp = top; // temp points to top of stack
			top = temp->next; // top of stack now points to next node
			delete temp; // top node is deleted
		}

		cout << "Stack is Now Empty" << endl;
	}
}

void print()
{
	node* temp = top;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}

	cout << endl;
}