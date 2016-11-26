#include<iostream>
#include<stack>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* head = NULL;

void reverse();
void Push(int);
void Print();

int main()
{
	int amount, val;

	cout << "How Many values are you pushing to your list: ";
	cin >> amount;

	for (int i = 0; i < amount; i++)
	{
		cout << "Enter a Value: ";
		cin >> val;
		Push(val);
	}
	Print();
	reverse();
	cout << "Here' your List, reversed: " << endl;
	Print();

	return 0;
}

void Push(int num)
{
	node* temp = new node(); // creates new node
	temp->data = num;// data field of node is filled
	temp->next = head; // node now points to what head node points to
	head = temp; // Node is now at the top of the list/stack
}

void reverse()
{
	if (head == NULL) // if list is empty, nothing to reverse
	{
		cout << "List is empty." << endl;
		return;
	}

	stack<node*> S; // creates a stack of node pointers
	node* temp = head; // pointer node at beginning of list
	while (temp != NULL)
	{
		S.push(temp); // pushes addresses to the stack
		temp = temp->next; // increments temp to next node
	}

	temp = S.top(); // temp now stores the address at the top of the stack
	head = temp; // head now stores that top address
	S.pop(); //pops that address held by temp
	while (!S.empty()) //while the stack is not empty
	{
		temp->next = S.top(); //the node now points to the node whose address is now at the top of stack/ node behind it
		S.pop(); // pops next address from stack to the temp pointer node
		temp = temp->next; // temp traverses to next node
	}

	temp->next = NULL; // last node in reversed list points to NULL
}

void Print()
{
	node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}

	cout << endl;
}