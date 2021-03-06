#include <iostream>
#include <queue>
#include <stack>
using namespace std;

/*--------Class for a single node of the root-------------*/

class Node
{
public:
	Node * lchild;  // link to left child of NODE
	int data;       // the data of the NODE
	Node * rchild;  // link to right child of NODE

	Node(int val)
	{
		lchild = nullptr;
		data = val;
		rchild = nullptr;
	}
};

/*--------------------------------------------------------*/





/**-------------HELPER FUCNTION TO MAKE A TREE-------------
 * 
 * WORKING OF Create() function
 * ------------------------------
 * 
 * 1) First we make a root node.
 * 2) Push the root node in a Queue.
 * 3) Dequeue to get the last pushed item (root)
 * 4) Accept the values of it's left and right nodes.
 * 5) If the left and right nodes exists push them into queue.
 * 6) Repeat Step 1, till the queue becomes empty. 
 * 
 **/

Node * create()
{
	Node * root;
	int data;

	// making the root node
	cout << "Enter the data of root node\n";
	cin >> data;
	root = new Node(data);

	queue<Node *> q;
	q.push(root);

	// while the queue is not empty, we will keep on processing 
	// If new node is created,it will be pushed in the queue
	// for further processing its left and right nodes.
	while(!q.empty())
	{
		Node * curr = q.front();  // getting the first pushed item
		q.pop();   // dequeing the first item
		int val;
		cout << "Enter the left child of " << curr->data << "\n";
		cin >> val;

		// if val is not -1 then we must create a new node
		if(val != -1)
		{
			Node * temp = new Node(val);  // creating a new Node
			curr->lchild = temp;    // making it the LC of the current node
			q.push(temp);  // enqueing the node to process later for its L&R Child
		}

		cout << "Enter the right child of " << curr->data << "\n";
		cin >> val;
		if(val != -1)
		{
			Node * temp = new Node(val);
			curr->rchild = temp;
			q.push(temp);
		}
		cout << "\n";
	}
	return root;
}
/*------------------------------------------------------------------*/






/*----------Inorder Traversal (Left->Root->Right)---------*/
void inOrder(Node * root)
{
	if(root != nullptr)
	{
		inOrder(root->lchild);
		cout << root->data << " ";
		inOrder(root->rchild);
	}
}
/*--------------------------------------------------------*/





/*----------------Level Order Traversal-------------------*/
void levelOrder(Node * root)
{
	if(root == nullptr)
		cout << "Empty Tree\n";
	
	queue <Node *> q;
	q.push(root);

	while(q.empty() != true)
	{
		Node * currentNode = q.front();
		cout << currentNode->data << " ";

		q.pop();		
		if(currentNode->lchild != nullptr)
			q.push(currentNode->lchild);

		if(currentNode->rchild != nullptr)
			q.push(currentNode->rchild);

	}
	cout << "\n";
}
/*-------------------------------------------------------*/






/*----------Function to delete the NODES of tree----------*/
void freeNodes(Node * root)
{
	if(root != nullptr)
	{
		freeNodes(root->lchild);
		Node * temp = root->rchild;
		delete root;
		freeNodes(temp);
	}
}
/*--------------------------------------------------------*/





/**-------------Function to print nodes level wise--------*/

void printLevelWise(Node * root)
{
	if(root == nullptr)
		return;

	queue<Node *> q;
	q.push(root);

	while(q.empty() != true)
	{
		int nodesCount = q.size();
		while(nodesCount)
		{
			if(q.front() == nullptr)
				cout << "-1 ";
			else
			{
				cout << q.front()->data << " ";
				q.push(q.front()->lchild);
				q.push(q.front()->rchild);
			}	
			q.pop();
			nodesCount--;
		}
		cout << "\n";
	}
}
/*---------------------------------------------------------*/

