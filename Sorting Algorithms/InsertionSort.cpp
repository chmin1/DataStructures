//This Program displays the INSERTION SORT ALGORITHM
//Given an Array of Values, The INSERTION SORT rearranges
//The array by taking values, placing them into temporary
//variables, and inserting them back into the array at 
//different positions

#include<iostream>
#include<vector>
using namespace std;

vector<int> InsertionSort(vector<int> B, int size)
{
	int value; //holds a value being shifted
	int hole; //holds the position where value will be inserted

	for (int i = 1; i < size; i++)
	{
		value = B[i];
		hole = i;

		/*While the hole is not at the beginning of the array
		And the value in the position before the hole is less
		than the value in the holder variable, shift the values
		until you've gotten to the correct space to insert the
		held value*/
		while (hole > 0 && B[hole - 1] > value)
		{
			B[hole] = B[hole - 1]; //shifts greater values in the array
			hole--; //moves the position for the insertion
		}
		B[hole] = value; //insert value into the new position
	}

	return B;
}

int main()
{
	int size;

	cout << "How many values would you like to put into your array: ";
	cin >> size;

	vector<int> A(size);

	for (int i = 0; i < size; i++)
	{
		cout << "Enter a Value: ";
		cin >> A[i];
	}

	cout << "Your Array, Unsorted: ";

	for (int i = 0; i < size; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	A = InsertionSort(A, size);

	cout << "Your Array, Sorted: ";

	for (int i = 0; i < size; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}