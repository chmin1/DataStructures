//This Program uses a Binary search to find the first 
//and last occurences of a value in a sorted array

#include<iostream>
#include "QuickSort.h"
using namespace std;


//Value takes a array, its size, and value being searched for
//returns the index of the value if found
int BinarySearch(int *D, int size, int val)
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
			high = mid - 1; //checks the left for reoccurences of val

			/*In order to change from searching for the first occurence 
			to the last, simply change mid - 1 to mid + 1*/
		}
		else if (val < D[mid]) 
			high = mid - 1; //search boundaries are now cut in half to all values lesser than mid
		else 
			low = mid + 1; //search boundaries are now cut in half to all values greater than mid
	}

	//if the loop finishes and returns first occurence of val
	return result;
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
		cout << "First occurence of value found at index " << pos << endl;

	return 0;
}