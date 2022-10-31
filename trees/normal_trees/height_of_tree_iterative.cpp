/**
 * Program to find the maximum height of a tree iteratively.
 * 
 * The idea is simple.
 * 
 * Perform a level order traversal.
 * During level order traversal, all the nodes at a particular level,
 * are present in a the queue. So just keep a count of how many times 
 * such levels are created and return that count as the maximum height 
 * of the tree.
 * 
 * 
 * TC : O(n) | SC : O(n) (For Queue)
 * 
**/

#include "tree.h"
using namespace std;

int getHeight(Node * root)
{
	int height = 0;

	queue<Node *> q;
	q.push(root);

	while(q.empty() != true)
	{
		// the number of nodes at a given level
		int nodeCount = q.size();


		while(nodeCount--)
		{
			// if the current node as any left or right child present
			// the push it in the queue (this will make up the other level)
			if(q.front()->lchild != nullptr)
				q.push(q.front()->lchild);

			if(q.front()->rchild != nullptr)
				q.push(q.front()->rchild);

			// after checking for the left and right child of current node,
			// delete it from the queue (freeing the queue for next level)
			q.pop();
		}

		// as soon as a level is done processing, increment the height.
		height++;
	}

	return height;	
}


int main()
{
	Node * root = create();
	cout << "The height of the tree is " << getHeight(root) << "\n";
	return 0;
}