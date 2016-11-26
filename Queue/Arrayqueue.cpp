#include <iostream>
using namespace std;

int A[10];
int front = -1; //initialize front of queue; head
int rear = -1; // initialize back of queue; tail

bool IsEmpty() // checks if queue is empty
{
	if (front == -1 && rear == -1)
		return true;
	else
		return false;
}

void EnQueue(int num) // adds value to the tail of queue
{
	if ((rear+1)%10 == front) // if the rear is at the end of the array, it is full
	{
		cout << "Queue is Full" << endl;
		return;
	}
	else if (IsEmpty() == true) //if the queue is empty
	{
		front = rear = 0; // set the rear and front to first index A[0]
	}
	else
	{
		rear = (rear + 1) % 10; // extend the rear of the queue for next value; circular array
	}
	A[rear] = num; // assigns another value to the queue
}

void DeQueue() //removes value from the front of the queue
{
	int holder;
	if (IsEmpty() == true)
	{
		cout << "Queue is Empty" << endl;
		return;
	}
	else if (front == rear) // if there is only one value in the queue
	{
		holder = A[front];
		front = rear = -1;
		cout << "removing from queue: " << holder << endl;
	}
	else
	{
		holder = A[front];
		front = (front + 1) % 10; //used for a circular array; if front is at the end, it will go back to beginning of array
		cout << "removing from queue: " << holder << endl;
	}
}

void print()
{
	int count = (rear + 10 - front) % 10 + 1;
	cout << "In Queue: ";
	for (int i = 0; i < count; i++)
	{
		int index = (front + i) % 10; //index for the queue of the array
		cout << A[index] << " ";
	}
}

int main()
{
	int val;
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter a Value to your queue: ";
		cin >> val;
		EnQueue(val);
	}
	print();
	cout << endl;
	DeQueue();
	DeQueue();
	print();

	return 0;
}