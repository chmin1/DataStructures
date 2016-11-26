#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* head;

void insert(int);
void reverse();
void print();

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
		insert(val);
	}
	cout << "Here is your list: " << endl;
	print();
	cout << "Now here is your list, reversed: " << endl;
	reverse();
	print();

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

void reverse() 
{
	node *current, *prev, *next;
	current = head; // current points to the first node
	prev = NULL;
	while (current != NULL)
	{
		next = current->next; // stores the address of thr next node
		current->next = prev; // current now points to the node prev pointed to
		prev = current; //prev now moves to where current is
		current = next; // current now moves to where next is
	}

	head = prev; //head now stores the last address, the one prev holds


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