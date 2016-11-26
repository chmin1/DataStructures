#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* head;

void insert(int); //inserts a integer at the end of the list
void print(); // prints all elements in the linked list
void Delete(int); // deletes node at POSITION

int main()
{
	head = NULL; //empty list;
	int n; // ask the user for a position
	int amount, amount2, val;

	cout << "How many Values will be in your list? ";
	cin >> amount;

	for (int i = 0; i < amount; i++)
	{
		cout << "Enter a Value: ";
		cin >> val;
		insert(val);
	}
	print();

	cout << "Enter a Position: ";
	cin >> n;

	Delete(n); // calls function to delete postion
	print(); //print list

	return 0;
}

void insert(int num)
{
	node* temp = new node(); //allocates space for a temp node
	temp->data = num;
	temp->next = NULL; //node will point to the end of the list
	if (head == NULL)
	{
		head = temp; //if the list is empty, temp now becomes the first node
	}
	else
	{
		node* temp2 = head; // node points to the head node
		while (temp2->next != NULL)
		{
			temp2 = temp2->next; // temp2 stores the address of the next node
		}
		temp2->next = temp; //temp2 now points to temp1
	}
	
}

void Delete(int pos)
{
	node* temp1 = head;
	
	//if deleting fist node
	if (pos == 1)
	{
		head = temp1->next; //points to whatever the first node pointed to
		delete temp1; // deallocates temp 1
		return;
	}

	for (int i = 0; i < pos - 2; i++)
	{
		temp1 = temp1->next; //temp1 points to the pos-1 node
	}
	node* temp2 = temp1->next; //nth node
	temp1->next = temp2->next; // points to the pos+1 node
	delete temp2; //deallocates memory allocated through new
	
}

void print()
{
	node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}