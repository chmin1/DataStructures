#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* head;

void insert(int);
void sort();
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
	cout << "Now here is your list, sorted: " << endl;
	sort();
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

void sort()
{
	node* temp = head;
	int holder;
	int counter = 0;
	while (temp->next != NULL)
	{
		temp = temp->next;
		counter++;
	}

	temp = head; // reset head

	for (int j = 0; j < counter; j++) //loops through every value in list
	{
		while (temp->next != NULL)  //iterate through list until next is null
		{
			if (temp->data > temp->next->data) //compares two values in the list
			{
				holder = temp->data; //holder takes the bigger value in the comparsion
				temp->data = temp->next->data; //temp takes the smaller value
				temp->next->data = holder; // the node after temp takes the bigger value
				temp = temp->next;
			}
			else
				temp = temp->next; //increment node
		}

		temp = head; //reset temp to head

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