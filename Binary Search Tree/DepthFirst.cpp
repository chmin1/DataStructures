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

//Traversing the list by depth
//this one is PREORDER TRAVERSAL
void Preorder(node* root)
{
	if (root == NULL) //if the pointer is empty, return
	{
		return;
	}
	//Preorder prints root node, then left node, then right node
	cout << root->data << " "; // print the value
	Preorder(root->left); // go to the left child first
	Preorder(root->right); // go to the right child second	
}

//this one is INORDER TRAVERSAL
void Inorder(node* root)
{
	if (root == NULL) //if the pointer is empty, return
	{
		return;
	}
	//Inorder prints left node, then root, then right node
	Inorder(root->left); // go to the left child first
	cout << root->data << " "; // print the value
	Inorder(root->right); // go to the right child second

	//Inorder traversal gives us values in sorted order
}

//this one is POSTORDER TRAVERSAL
void Postorder(node* root)
{
	if (root == NULL) //if the pointer is empty, return
	{
		return;
	}
	//Postorder prints left node, then right node, then root
	Postorder(root->left); // go to the left child first
	Postorder(root->right); // go to the right child second
	cout << root->data << " "; // print the value
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

	Preorder(rootPtr);
	cout << endl;

	Inorder(rootPtr);
	cout << endl;

	Postorder(rootPtr);
	cout << endl;

	return 0;
}