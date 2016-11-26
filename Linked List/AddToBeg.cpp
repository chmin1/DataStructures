#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* head; // head node; stores only a pointer

void insertBeg(int); // function used to insert a node into the list

void print(); // function used to print the list

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
		insertBeg(num);
		print();
	}

	return 0;
}

void insertBeg(int number)
{
	node* temp = new node(); //allocates a new node named temp, dynamically allocated size
	temp->data = number; // sets the data of that new node to the integer inputted in main
	temp->next = head; //temp points to the same address as head
	head = temp; //makes temp the first node

	
	return;
}
//
//void print()
//{
//	node* temp = head; // creates a node, pointed at the head node
//	
//	cout << "Your List:";
//	while (temp != NULL) // traverses list; outputs value of a node, then moves to next node
//	{
//		cout << " " << temp->data;
//		temp = temp->next;
//	}
//
//	cout << endl;
//	return;
//}