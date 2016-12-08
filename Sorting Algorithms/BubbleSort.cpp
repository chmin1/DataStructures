//This Program displays the BUBBLE SORT ALGORITHM
//Given an Array of Values, The BUBBLE SORT scans
//The array multiple times and compares the value
//at a certain index with other values in the array

#include<iostream>
#include<vector>
using namespace std;

vector<int> BubbleSort(vector<int> B, int size)
{
	int temp; //variable will be used to swap values

	//The outer loop will index a value in the array
	for (int i = 0; i < size; i++)
	{
		//The inner loop will compare the 
		//indexed value wit the rest of the loop
		for (int j = i; j < size; j++)
		{
			if (B[j] < B[i])
			{
				temp = B[i]; // temp holds the larger value
				B[i] = B[j]; // The value with the smaller index takes the smaller value
				B[j] = temp; // The larger index  takes the value held in temp
			}
		}
	}

	return B; //returns array

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

	A = BubbleSort(A, size);

	cout << "Your Array, Sorted: ";

	for (int i = 0; i < size; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}