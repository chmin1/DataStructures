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

int main()
{
	int amount, val;
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

	return 0;

}