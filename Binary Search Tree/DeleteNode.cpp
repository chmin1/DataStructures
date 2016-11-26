//DELETES A NODE FROM A BINARY SEARCH TREE
//DELETE NODES WITH CHILDREN WITHOUT LOSING MEM. ADDRESS OF CHILDREN
//AFTER DELETION, TREE SHOULD STILL BE A BINARY SEARCH TREE
#include<iostream>
#include<queue>
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

//Finds Minimum value in a tree
node* FindMin(node* rootPtr)
{
	while (rootPtr->left != NULL) 
		rootPtr = rootPtr->left;
	return rootPtr;
}

//Finds the node containing a value to be deleted
node* DeleteNode(node* rootPtr, int data)
{
	//Base Case
	if (rootPtr == NULL)
		return rootPtr;
	
	//If the value being searched for is less than the current root
	else if (data < rootPtr->data)
		rootPtr->left = DeleteNode(rootPtr->left, data);
	
	//If the value being searched for is greater than the current root
	else if (data > rootPtr->data)
		rootPtr->right = DeleteNode(rootPtr->right, data);

	//Once you've found the value, set up 3 cases
	else
	{
		//Case 1: No Child AKA a leaf node; Delete the leaf Node
		if (rootPtr->left == NULL && rootPtr->right == NULL)
		{
			delete rootPtr;
			rootPtr = NULL;
		}

		//Case 2.1: One child/No Left Child
		else if (rootPtr->left == NULL)
		{
			node * temp = rootPtr;
			rootPtr = rootPtr->right;
			delete temp;
		}

		//Case 2.2: One child/No Right Child
		else if (rootPtr->right == NULL)
		{
			node * temp = rootPtr;
			rootPtr = rootPtr->left;
			delete temp;
			
		}

		//Case 3: 2 Children
		else
		{
			//Finds Minimum value in right subtree of node to be deleted
			//Assigns a temp pointer-to-node to minimum value in right tree
			node * temp = FindMin(rootPtr->right);
			//value of the root is rewritten with the minimum value
			rootPtr->data = temp->data;
			//Makes a recursive call to delete right subnode
			rootPtr->right = DeleteNode(rootPtr->right, temp->data);
		}
	}

	return rootPtr;
}

//Traversing the list Level by level
//also called LEVEL ORDER TRAVERSAL
void breathFirst(node* root)
{
	if (root == NULL)
	{
		cout << "Tree is Empty..." << endl;
		return;
	}
	queue<node*> Q; //queue will be used to store pointers-to-nodes in the tree
	Q.push(root); // push the address of root node, the node on the first level

	while (!Q.empty()) // while the queue has values inside of it
	{
		node* current = Q.front(); // create a temp pointer-to-node and assign it to the front item in the queue
		cout << current->data << " "; // output data in queue

		//Now the function will collect the addresses of the children of the outputted node
		//The children will be pushed to the queue from left to right
		if (current->left != NULL)
			Q.push(current->left);
		if (current->right != NULL)
			Q.push(current->right);

		Q.pop(); //removes pointer at front of queue
	}

	cout << endl;
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

	breathFirst(rootPtr);

	cout << "Enter A value to be deleted: ";
	cin >> val;

	DeleteNode(rootPtr, val);

	breathFirst(rootPtr);

	return 0;
}