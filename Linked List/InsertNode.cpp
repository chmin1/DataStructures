#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* head;
void insert(int, int); //takes 2 arguements, the value and its position
void print();

int main()
{
	head = NULL; //empty list
	int amount, val, place;

	cout << "How Long will your list be? ";
	cin >> amount;

	for (int i = 0; i < amount; i++)
	{
		cout << "Enter Value: "; 
		cin >> val;
		if (i == 0)
		{
			place = 1;
		}
		else
		{
			cout << "Enter Position: ";
			cin >> place;
		}
		insert(val, place);
	}
	print();

	return 0;
}

void insert(int num, int pos)
{
	node* temp1 = new node();
	temp1->data = num;
	temp1->next = NULL; // frst insert, first position

	//inserting at the first position
	if (pos == 1)
	{
		temp1->next = head; //set link to the existing head field
		head = temp1; //head now points to the new head
		return;
	}

	//for all other cases, go to the pos-1 node
	node* temp2 = head; // create a temp variable, store the address of head node
	for (int i = 0; i < pos - 2; i++) //pos-2 points temp2 to the pos-1 node
	{
		temp2 = temp2->next;
	}
	temp1->next = temp2->next; //link field of the new node node has the link field of the pos-1 node
	temp2->next = temp1; // pos-1 node now points to the new node

	return;
}

void print()
{
	node* temp = head;
	cout << "Your List: ";
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}