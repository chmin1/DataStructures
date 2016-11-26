#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
	node* prev;
};

node* head;
void Insert(int);
void print();
void reverseprint();


int main()
{
	head = NULL; //empty list;
	int amount, val;

	cout << "How many Values will be in your list? ";
	cin >> amount;

	for (int i = 0; i < amount; i++)
	{
		cout << "Enter a Value: ";
		cin >> val;
		Insert(val);
	}
	cout << "Here is your list: " << endl;
	print();
	cout << "Here is your list, Reversed: " << endl;
	reverseprint();

	return 0;
}

//inserts at beginning of list
//void Insert(int x)
//{
//	node* temp = new node(); // creates new node
//	temp->data = x;
//	temp->next = NULL;
//	temp->prev = NULL;
//
//	if (head == NULL) // if the list is empty, this will be the first node
//	{
//		head = temp;
//	}
//	else
//	{
//		head->prev = temp; // the node head points to now points to the new node
//		temp->next = head; // the new node points to what head points to/the node after it
//		head = temp; // head points to the new node
//	}
//}

//inserts to the end of the list
void Insert(int num)
{
	node* temp = new node(); //allocates space for a temp node
	temp->data = num;
	temp->next = NULL; //node will point to the end of the list
	temp->prev = NULL;

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
		temp2->next = temp; //temp2 now points to temp
		temp->prev = temp2; // temp points back to temp2
	}

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

void reverseprint()
{
	node* temp = head;
	if (temp == NULL)
		return;

	while (temp->next != NULL)
	{
		temp = temp->next; //traverse list to last node
	}

	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->prev; //prints list backwards using prev pointer
	}
	cout << endl;
}