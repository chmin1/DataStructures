//Given a sorted array with no duplicates,
//This prgram determines how many times an
//array has been rotated

#include<iostream>
//#include "QuickSort.h"
using namespace std;

int FindRotation(int *D, int size)
{
	int low = 0;
	int high = size - 1;

	while (low <= high)
	{
		//if the array is already sorted, return low 
		if (D[low] <= D[high]) // Case 1
			return low; //list was not rotated
		
		//else calculate mid, prev and next
		int mid = (low + high) / 2;
		int next = (mid + 1) % size;
		int prev = (mid + size - 1) % size;

		if (D[mid] <= D[next] && D[mid] <= D[prev]) //case 2
			return mid; //list was rotated "mid" times

		//if array is unsorted, one of these two conditions will run
		else if (D[mid] <= D[high])
			high = mid - 1; // discard right side of list

		else if (D[mid] >= D[low])
			low = mid + 1; // discard left side of list
	}

	return -1; //invalid
}

int main()
{
	int size, val, count;

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

	count = FindRotation(A, size);

	cout << "This Array was rotated " << count << " times." << endl;
}