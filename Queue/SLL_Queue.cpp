#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* front = NULL; //points to front of the queue; head
node* rear = NULL; //points to the tail of queue

void Enqueue(int); //adds a value to the tail of the queue
void Dequeue(); //takes a value from the front of queue
void Front(); //shows the frontmost value of the queue
void Print(); //Prints the queue from front to rear

int main()
{
	int amount, val, case_choice;
	char again;
	cout << "How many values will you be adding to the queue: ";
	cin >> amount;
	for (int i = 0; i < amount; i++)
	{
		cout << "Enter A Value: ";
		cin >> val;
		Enqueue(val);
	}

	Print();

	do
	{
		cout << "What would you like to do next?" << endl
			<< "1. Add a value to the Queue" << endl
			<< "2. Remove a Value from the Queue" << endl
			<< "3. See the value at the front of the Queue" << endl
			<< "4. Quit" << endl << endl
			<< "Your Choice (1-4): ";
		cin >> case_choice;
		while (case_choice < 1 || case_choice > 4)
		{
			cout << "Invalid Choice, Try Again: ";
			cin.ignore();
			cin >> case_choice;
		}

		switch (case_choice)
		{
		case 1:
			cout << "Input A Value: ";
			cin >> val;
			Enqueue(val);
			Print();
			break;
		case 2:
			cout << "Dequeuing fron list..." << endl;
			Dequeue();
			break;
		case 3:
			Front();
			break;
		case 4:
			break;
		}

		cout << "Would you like to do something else (Y/N): ";
		cin >> again;
	} while (again == 'Y' || again == 'y');
	return 0;
}

//Enters a value to the rear of the list
void Enqueue(int num)
{
	node* temp = new node();
	temp->data = num;
	temp->next = NULL;
	
	//conditional: If the Queue is Empty, front and rear point to same node
	if (front == NULL && rear == NULL)
	{
		front = rear = temp;
	}
	else// if the list is not empty
	{
		rear->next = temp; // node at the tail of queue now points to the new node
		rear = temp; // rear is now assigned to point to temp
	}
}

//Deletes a value from the front of the list
void Dequeue()
{
	node* temp = front;

	if (front == NULL)
	{
		cout << "Queue is already Empty" << endl;
		return;
	}
	else if (front == rear) //if the list contains 0nly one node
	{
		front = rear = NULL; // assign front and rear to NULL; empty the queue
		cout << temp->data << endl;
		Print();
		delete(temp); //delete the node/clear the queue
	}
	else // for a list with multiple nodes
	{
		front = front->next; // front is now assigned to point to the next node
		cout << temp->data << endl;
		Print();
		delete(temp); // delete the node in front/dequeue
	}
}

void Front() // returns the forst value in the list to be dequeued
{
	if (front == NULL)
	{
		cout << "Your queue is empty" << endl;
		return;
	}
	else
	{
		cout << "The first value to be Dequeued is: " << front->data << endl;
		return;
	}
}

void Print()
{
	node* temp = front;
	cout << "Queued: ";
	while (temp->next != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}