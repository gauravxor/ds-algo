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
 * Approach (Recursive)
 * TC : O(n) | SC : O(n)
 * ---------------------
 * 
 * Start traversing the tree from top, i.e. ROOT.
 * Using a variable keep a track of whether a particular
 * level is visited earlier or begin visited for the first
 * time. 
 * If visiting for the first time, print the data of current node
 * and set the maxVisitedLeve to the currentLevel as a marker.
 * If not visiting for the second time, then we dont have to do
 * anything.
 *  
 **/

#include "tree.h"

// the maximum level we have visited in the tree till now.
int maxVisitedLevel = 0;

void leftView(Node * root, int currentLevel)
{
	if(root == nullptr)
		return;

	// if we have not yet visited the currentLevel, then
	// the current node is the first node of the currentLevel,
	// so we will print it.
	if(maxVisitedLevel < currentLevel)
	{
		cout << root->data << " ";

		// as we are done with the currentLevel, we
		// set the maxVisitedLevel to currentLevel, so that
		// other nodes of the same level should not get printed.
		maxVisitedLevel = currentLevel;
	}

	// as we go down deeper into the tree towards the left and 
	// right subtree of the currentNode, we are incrementing the 
	// currentLevel by one (denoting the increase in level)
	leftView(root->lchild, currentLevel + 1);
	leftView(root->rchild, currentLevel + 1);
}

int main()
{
	Node * root = create();

	cout << "The left view of the tree is\n";
	leftView(root, 0);
	cout << "\n";
	return 0;
}