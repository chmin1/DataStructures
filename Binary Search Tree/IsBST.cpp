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

int FindMin(node* rootPtr)
{
	if (rootPtr == NULL) //if the tree is empty, return a -1
		return -1;

	/*the smallest number is the leftmost subchild. traverse the
	tree to the left until you've reached the leftmost child*/

	while (rootPtr->left != NULL)
		rootPtr = rootPtr->left;

	//rootPtr here is local, meaning it will not change the real root

	return rootPtr->data;
}

int FindMax(node* rootPtr)
{
	if (rootPtr == NULL) //if the tree is empty, return a -1
		return -1;

	/*the largest number is the rightmost subchild. traverse the
	tree to the right until you've reached the rightmost child*/

	while (rootPtr->right != NULL)
		rootPtr = rootPtr->right;

	//rootPtr here is local, meaning it will not change the real root

	return rootPtr->data;
}

//Returns True if Tree is a BST, False Otherwise
bool IsBST(node* rootPtr, int minVal, int maxVal)
{
	//Base Case
	if (rootPtr == NULL)
		return true;


	//Set a conditional that checks for 4 conditions
	// Is Value in left child Greater Than or Equal to Min value
	// Is Value in right child Lesser Than or Equal to Max value
	// Makes recursive calls to left and right subtrees to see if they fulfill previous two conditions
	if ( rootPtr->data >= minVal
		&& rootPtr->data <= maxVal
		&& IsBST(rootPtr->left, minVal, rootPtr->data)
		&& IsBST(rootPtr->right, rootPtr->data, maxVal))
		return true;
	else
		return false;
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

	min = FindMin(rootPtr);
	max = FindMax(rootPtr);

	cout << "Min = " << min << endl
		<< "Max = " << max << endl;

	if (IsBST(rootPtr, min, max) == true)
		cout << "This Is A Binary Search Tree" << endl;
	else
		cout << "This Is Not A Binary Search Tree." << endl;

	return 0;
}