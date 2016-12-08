//This program uses a binary search to count 
//the number of times a value occurs in a list

#include<iostream>
#include "QuickSort.h"
using namespace std;

int BinarySearch(int *D, int size, int val, bool SearchFirst)
{
	int low = 0; //beginning of the array
	int high = size - 1; //end of the array
	int result = -1; //holds index of value
	
	while (low <= high)
	{
		int mid = (low + high) / 2; //middle of array
		if (val == D[mid]) 
		{
			result = mid; //stores index in the result
			if (SearchFirst == true) //finds index of the first occurence
				high = mid - 1;
			else //finds index of last occurence
				low = mid + 1;
		}
		else if (val < D[mid]) 
			high = mid - 1; //search boundaries are now cut in half to all values lesser than mid
		else 
			low = mid + 1; //search boundaries are now cut in half to all values greater than mid
	}

	return result;
}

int main()
{
	int size, val, firstIndex, lastIndex;

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

	firstIndex = BinarySearch(A, size, val, true); //finds the first occurence of a number

	if (firstIndex == -1)
	{
		cout << "No value was found" << endl;
	}
	else
	{
		lastIndex = BinarySearch(A, size, val, false); //Finds the last occurence
		cout << "The number of occurences of " << val << " is " << lastIndex - firstIndex + 1 << endl;
	}

	return 0;
}