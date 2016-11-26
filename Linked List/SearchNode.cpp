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
bool search(int); 

int main()
{
	head = NULL; //empty list;
	int n; // ask the user for a position
	int amount, val;

	cout << "How many Values will be in your list? ";
	cin >> amount;

	for (int i = 0; i < amount; i++)
	{
		cout << "Enter a Value: ";
		cin >> val;
		insert(val);
	}

	cout << "Search for a number ";
	cin >> n;

	if (search(n) == true)
	{
		cout << "That value is in the list" << endl;
	}
	else
	{
		cout << "That value is NOT in the list" << endl;
	}
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

bool search(int num)
{
	node* temp = head;

	while (temp != NULL)
	{
		if (temp->data == num)
			return true;
		temp = temp->next;
	}
	return false;
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