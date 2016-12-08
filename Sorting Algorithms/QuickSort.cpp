//This Program displays the Quick SORT ALGORITHM
//Much like the Merge Sort, The QUICK SORT halves
//the array without making 2 separate arrays using 
//a pivot value. The array then sorts the halves
#include<iostream>
using namespace std;

//Rearranges the array from the the pivot
//values left of the pivot will be lesser than pivot
//values right of the pivot will be greater than pivot
int Partition(int *C, int start, int end)
{
	int pivot = C[end]; //pivot is set to the last value in the array
	int pIndex = start; //index is set to the start of the array
	int holder;

	//This loop will swap the values in the array
	//using the pivot as a conditional
	for (int i = start; i < end; i++)
	{
		//if value at current index is less than the value at pivot
		//swap the values at current index with value at pIndex
		if (C[i] <= pivot)
		{
			holder = C[pIndex];
			C[pIndex] = C[i];
			C[i] = holder;
			pIndex++;
		}
	}

	//now the values at pIndex must be swapped with the pivot
	holder = C[pIndex];
	C[pIndex] = C[end];
	C[end] = holder;

	return pIndex; //returns partition index
}

//Marks the boundaries of an array without
//creating new arrays. Then passes them to be sorted
void QuickSort(int *B, int start, int end)
{
	if (start < end)
	{
		//calls to function to return index of pivot
		int pIndex = Partition(B, start, end);

		//Make 2 recursive calls
		//one to sort values left of pivot
		//one to sort values right of pivot
		QuickSort(B, start, pIndex - 1); //from start of array till before pivot
		QuickSort(B, pIndex + 1, end); //from after pivot till end
	}
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

	QuickSort(A, 0, size - 1);

	cout << "Your Array, Sorted: ";

	for (int i = 0; i < size; i++)
	{
		cout << *(A + i) << " ";
	}
	cout << endl;

	return 0;
}