//In a Binary Search Tree, This Program will find
//the successor of a value in a Inorder Traversal
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

//Function to search for a node by Value
node* search(node* rootPtr, int num) // searches tree for a value
{
	if (rootPtr == NULL)
	{
		return NULL;
	}
	else if (rootPtr->data == num)
		return rootPtr;
	else if (num <= rootPtr->data)
		return search(rootPtr->left, num); //if the data is less than whats in the current node, search left subtree
	else if (num > rootPtr->data)
		return search(rootPtr->right, num);
}

//This Function will find the Inorder Successor of a node
int InorderSuccessor(node* rootPtr, int data)
{
	// Search for the node
	node* current = search(rootPtr, data);

	if (current == NULL)
		return 0;

	//Case 1: Current node has a right subtree
	else if (current->right != NULL)
	{
		//find the leftmost child of that right subtree
		node* temp = current->right;
		while (temp->left != NULL)
			temp = temp->right;
		return temp->data;
	}

	//Case 2: No Right Tree
	else
	{
		node* successor = NULL;
		node* ancestor = rootPtr;

		while (ancestor != current)
		{
			if (current->data < ancestor->data)
			{
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		return successor->data;
	}
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

	cout << "Enter a Value to Find its Inorder Successor: ";
	cin >> val;

	cout << "The Inorder successor of " << val << " is " << InorderSuccessor(rootPtr, val) << endl;

	return 0;
}