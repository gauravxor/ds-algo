/**
 * Program to print nodes present at a distance K, from the
 * top(root) of the tree using recursion.
 * 						OR
 * Program to print all the nodes present at Level K, using recursion.
 **/

#include "tree.h"



void nodesAtK(Node * root, int k)
{
	if(root ==  nullptr)
		return;

	if(k == 0)
		cout << root->data << " ";

	nodesAtK(root->lchild, k - 1);
	nodesAtK(root->rchild, k - 1); 
}

int main()
{
	Node * root = create();

	cout << "Enter the distance from root\n";
	int k;
	cin >> k;
	cout << "Nodes at level " << k << " is\n"; 
	nodesAtK(root, k - 1);
	cout << "\n";
	return 0;
}
