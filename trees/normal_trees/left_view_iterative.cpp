/**
 * Code to print the left view of a binary tree
 * 
 * If the tree is like this, then the left view of this tree
 * will be [2, 3, 5].
 * 
 * 
 *  	   2
 *	 	  / \
 *	 	 3   4
 *	 	/ \   \
 *	   5   6   9
 * 
 * Left View basically means, that those nodes that are visible
 * only from the left hand side of the tree.
 * 
 * 
 * Approach (Iterative)
 * TC : O(n) | SC : O(n)
 * ---------------------
 * 
 * Start traversing the tree from top, i.e. ROOT.
 * Push all the element of the currentLevel in a queue.
 * While pushing into the queue, just check for the first
 * node getting inserted and print that particular node.
 *  
 **/


#include "tree.h"

void leftView(Node *root)
{
	if(root == nullptr)
		return;

	queue<Node *> q;
	q.push(root);

	while(q.empty() == false)
	{
		
		int isFirst = 1;
		
		// this gives the width of the tree at the currentLevel
		int currentWidth = q.size();


		while(currentWidth--)
		{
			Node * currentNode = q.front();

			// if we are dealing with the first element,
			// print it and set the isFirst flag to 0, to
			// prevent further printing.
			if(isFirst == 1)
			{
				cout << currentNode->data << " ";
				isFirst = 0;
			}

			// insert the left and right child of the currentNode
			// into the queue for further processing.
			if(currentNode->lchild != nullptr)
				q.push(currentNode->lchild);
			if(currentNode->rchild != nullptr)
				q.push(currentNode->rchild);
			q.pop();
		}		
	}
}


int main()
{
	Node *root = create();
	cout << "The left view of the tree is\n";
	leftView(root);
	cout << "\n";
	return 0;
}