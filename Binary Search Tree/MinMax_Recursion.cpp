#include<iostream>
using namespace std;

struct node
{
	int data;
	node* left; // points to the left child of the node
	node* right; // points to the right child of the node
};

node* newNode(int num) // creates node to be inserted in the tree
{
	node*  temp = new node();
	temp->data = num;
	temp->right = temp->left = NULL;
	return temp;
}

node* insert(node* rootPtr, int num) //inserts the node into its proper place in the tree
{
	if (rootPtr == NULL) //if the rootPtr is NULL the new node will be the first node/root
	{
		rootPtr = newNode(num);
	}
	else if (num <= rootPtr->data) // if the data in new node is less than the data in its root
	{
		rootPtr->left = insert(rootPtr->left, num); //recursive call to insert as left child
		//recusion won't stop until rootPtr is NULL
	}
	else if (num > rootPtr->data)
	{
		rootPtr->right = insert(rootPtr->right, num);
		//same principle for left child
	}

	return rootPtr;
}

bool search(node* rootPtr, int num) // searches tree for a value
{
	if (rootPtr == NULL)
	{
		return false;
	}
	else if (rootPtr->data == num)
		return true;
	else if (num <= rootPtr->data)
		return search(rootPtr->left, num); //if the data is less than whats in the current node, search left subtree
	else if (num > rootPtr->data)
		return search(rootPtr->right, num);
}

//Recursive method for finding Min and Max Values

int FindMin(node* rootPtr)
{
	if (rootPtr == NULL) //if the tree is empty, return a -1
		return -1;

	/*the smallest number is the leftmost leaf. traverse the
	tree to the left until you've reached the leftmost leaf*/

	else if (rootPtr->left == NULL)
		return rootPtr->data; // return data if you've gotten to the leftmost leaf

	//rootPtr here is local, meaning it will not change the real root

	return FindMin(rootPtr->left); // call the function again, using different root
}

int FindMax(node* rootPtr)
{
	if (rootPtr == NULL) //if the tree is empty, return a -1
		return -1;

	/*the largest number is the rightmost leaf. traverse the
	tree to the right until you've reached the rightmost leaf*/

	else if (rootPtr->right == NULL)
		return rootPtr->data; // return data if you've found rightmost leaf

	//rootPtr here is local, meaning it will not change the real root

	return FindMax(rootPtr->right); // call the function again, using different root
}

int main()
{
	int amount, val, min, max;
	node* rootPtr = NULL; // creates head of list that will point to root of tree
	//insert Nodes into the tree, change the root as it continues

	cout << "How many values will be in your tree: ";
	cin >> amount;
	for (int i = 0; i < amount; i++)
	{
		cout << "Enter a Value: ";
		cin >> val;
		rootPtr = insert(rootPtr, val);
	}

	cout << "Enter a value to be searched for in the tree: ";
	cin >> val;
	if (search(rootPtr, val) == true)
		cout << "Value has been found!" << endl;
	else
		cout << "Not in tree" << endl;

	min = FindMin(rootPtr);
	max = FindMax(rootPtr);
	if (min == -1)
		cout << "Your Tree is Empty" << endl;
	else
	{
		cout << "Minimum Value: " << min << endl;
		cout << "Maximum Value: " << max << endl;
	}

	return 0;
}