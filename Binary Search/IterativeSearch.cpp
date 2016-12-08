//This Program illustrates the BINARY SEARCH ALGORITHM
//Given a sorted array of values, this method cuts the
//array in half, determines whether the middle value is
//Greater Than or Less than value being searched for
//and continues this process until the value is found

#include<iostream>
#include "QuickSort.h"
using namespace std;

//Value takes a array, its size, and value being searched for
//returns the index of the value if found
int BinarySearch(int *D, int size, int val)
{
	int low = 0; //beginning of the array
	int high = size - 1; //end of the array
	
	while (low <= high)
	{
		int mid = (low + high) / 2; //middle of array
		if (val == D[mid])
			return mid + 1; // Value found, return index
		else if (val < D[mid]) //if the value is < mid, change the boudaries of the search
			high = mid - 1; //search boundaries are now cut in half to all values lesser than mid
		else //if the value is > mid, change the boudaries of the search
			low = mid + 1; //search boundaries are now cut in half to all values greater than mid
	}

	//if the loop finishes and the value is not found
	return -1;
}

int main()
{
	int size, val, pos;

	cout << "How many values would you like to put into your array: ";
	cin >> size;

	int *A = new int[size];

	for (int i = 0; i < size; i++)
	{
		cout << "Enter a Value: ";
		cin >> *(A + i);
	}

	cout << "Your Array, Unsorted: ";

	for (int i = 0; i < size; i++)
	{
		cout << *(A + i) << " ";
	}
	cout << endl;

	QuickSort(A, 0, size - 1);

	cout << "Your Array, Sorted: ";

	for (int i = 0; i < size; i++)
	{
		cout << *(A + i) << " ";
	}
	cout << endl;

	cout << "Please enter a value to be seached for: ";
	cin >> val;

	pos = BinarySearch(A, size, val);

	if (pos == -1)
	{
		cout << "No value was found" << endl;
	}
	else
		cout << "Value found at position " << pos << endl;

	return 0;
}