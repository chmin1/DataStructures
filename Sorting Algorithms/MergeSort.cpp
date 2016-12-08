//This Program displays the MERGE SORT ALGORITHM
//Given an Array of Values, The MERGE SORT halves
//An array then sorts the two halves. Then the
//halves are merged back together
#include<iostream>
using namespace std;

//Merges two arrays into one, sorted array
void Merge(int *C, int *L, int leftSize, int *R, int rightSize)
{
	//Indexes for left, right subarray and merged array
	int i = 0, j = 0, k = 0;

	while (i < leftSize && j < rightSize) // compares values in both arrays
	{
		//Compares both arrays at their respective indexes,
		//Store the lesser value of the two into the merged array
		if (L[i] < R[j])
		{
			C[k] = L[i]; //Stores left array value
			i++; //Increment left array
		}
		else
		{
			C[k] = R[j]; //Stores right array value
			j++; //Increment right array
		}
		k++; //increment merged array index at the end of each iteration
	}

	//These loops are used for leftover values
	//once the condition of the first loop is no longer met
	while (i < leftSize)
	{
		C[k] = L[i];
		k++;
		i++;
	}
	while (j < rightSize)
	{
		C[k] = R[j];
		k++;
		j++;
	}
}

void MergeSort(int *B, int size)
{
	int mid, *L, *R;
	//conditional to stop infinite recursive loop
	if (size == 1)
		return;

	mid = size / 2; //holds the middle index
	L = new int[mid]; //Pointer to new left subarray
	R = new int[size - mid]; //Pointer to new right subarray

	//This Loop fills the left array with values 0 <= i < mid
	for (int i = 0; i < mid; i++)
	{
		L[i] = B[i];
	}

	//This Loop fills the right array with values mid <= i < size
	for (int j = mid; j < size; j++)
	{
		R[j - mid] = B[j];
	}

	//Recursive calls to sort left and right arrays
	MergeSort(L, mid);
	MergeSort(R, size - mid);

	Merge(B, L, mid, R, size - mid); // Merges L and R into sorted list
	delete(L); // Deletes L
	delete(R); // Deletes R
}

int main()
{
	int size;

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

	MergeSort(A, size);

	cout << "Your Array, Sorted: ";

	for (int i = 0; i < size; i++)
	{
		cout << *(A + i) << " ";
	}
	cout << endl;

	return 0;
}