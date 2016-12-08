//Given a sorted array with no duplicates,
//uses binary search to find a element in
//a sorted, rotated array

#include<iostream>
//#include "QuickSort.h"
using namespace std;

int BinarySearch(int *D, int size, int val)
{
	int low = 0;
	int high = size - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (val == D[mid])
			return mid; //found index of number

		if (D[mid] <= D[high]) //If the right half is sorted
		{
			if (val > D[mid] && val <= D[high])
				low = mid + 1; //Search the sorted right half
			else
				high = mid - 1;
		}
		else //left half is sorted
		{
			if (D[low] <= val && val < D[mid]) //search the left sorted half
				high = mid - 1;
			else
				low = mid + 1;
		}
	}

	return -1; //invalid
}

int main()
{
	int size, val, pos;

	cout << "How many values would you like to put into your array: ";
	cin >> size;

	int *A = new int[size];

	//This code does not contain a function to rotate sorted arrays
	// Sample array to enter:
	// {15, 22, 23, 28, 31, 38, 5, 6, 8, 10, 12}
	for (int i = 0; i < size; i++)
	{
		cout << "Enter a Value: ";
		cin >> *(A + i);
	}

	cout << "Enter A Value to be search for: ";
	cin >> val;

	pos = BinarySearch(A, size, val);

	cout << "Value found at index " << pos << endl;

	return 0;
}