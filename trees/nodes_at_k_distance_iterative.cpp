/**
 * Program to print nodes present at a distance K, from the
 * top(root) of the tree, without using recursion.
 * 						OR
 * Program to print all the nodes present at Level K, without 
 * using recursion.
 **/

#include "tree.h"



void nodesAtK(Node * root, int k)
{
	if(root ==  nullptr)
		cout << "Tree is empty\n";

	cout << "\nNodes at distance " << k << " are\n";
	queue <Node *> q;
	q.push(root);

	while(q.empty() != true)
	{
		int nodeCount = q.size();
		while(nodeCount--)
		{
			if(k == 0)
				cout << q.front()->data << " ";

			if(q.front()->lchild != nullptr)
				q.push(q.front()->lchild);

			if(q.front()->rchild != nullptr)
				q.push(q.front()->rchild);

			q.pop();
		}
		k--;
	}
	cout << "\n";
}

int main()
{
	Node * root = create();

	cout << "Enter the distance from root\n";
	int k;
	cin >> k;

	nodesAtK(root, k - 1);
	cout << "\n";
	return 0;
}
