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

int main()
{
	int list_size, num;

	head = NULL; //empty list

	cout << "How many numbers will be in your list? ";
	cin >> list_size; // declares size of the linked list

	for (int i = 0; i < list_size; i++)
	{
		cout << "Enter A Number: ";
		cin >> num;
		insert(num);
		print();
	}

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