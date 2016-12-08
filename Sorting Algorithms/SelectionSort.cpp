//This Program displays the SELECTION SORT ALGORITHM
//Given an Array of Values, The SELECTION SORT creates
//a new array, takes the minimum value in the old array
//at each pass, and inserts that value in the new array

#include<iostream>
#include<vector>
using namespace std;

vector<int> SelectionSort(vector<int> B, int amount)
{
	//Create a for-loop that passes through the array n-2 times
	for (int i = 0; i < amount - 1; i++)
	{
		int min = i; //Holds the current position of the outer loop

		for (int j = i + 1; j < amount; j++)
		{
			//If a value is found to be less than the one at the current index
			//update the index of the minimum element
			if (B[j] < B[min])
				min = j;
		}

		/*These next set of instructions are used to switch values in an array*/

		int temp = B[i]; // create a temp variable to hold value at current index
		B[i] = B[min]; // Update value at current index with the minimum value in array
		B[min] = temp; // replace the old minimum value with the value in temp
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

	A = SelectionSort(A, size);

	cout << "Your Array, Sorted: ";

	for (int i = 0; i < size; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}