#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* head;

void insert(int);
void print(node*);
void reverse(node*);

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
	print(head);
	cout << endl;
	cout << "Now here is your list, reversed: " << endl;
	reverse(head);
	print(head);
	cout << endl;

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

void print(node* head)
{
	node* temp = head;
	if (temp == NULL)
		return; // if list is empty, there is nothing to print
	else
	{
		cout << temp->data << " "; // outputs first value
		print(head->next); // calls the function inside of itself to run again; recursion
	}
}

void reverse(node* temp) //reverse list order using recursion
{
	if (temp->next == NULL) // exit condition
	{
		head = temp;
		return;
	}
	reverse(temp->next); // calls the function inside of itself to run; recursion
	//next lines will reverse the pointers of the list
	node* temp2 = temp->next; // temp2 points to the node temp currently points to
	temp2->next = temp; //temp2 now points back to temp
	temp->next = NULL; // temp now points to NULL; NULLIFIES original pointer
}