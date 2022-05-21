/**
 * Code to check if the given binary tree is balanced.
 * 
 * A binary tree is called balanced, if the difference
 * between the height of the left and right subtree is
 * at most 1.
 * 
 * Balanced binary tree | Unbalanced binary tree
 *     5		     	|	    5
 *    / \				|	   / \ 
 *	 1   4				|     2   3
 *      / \				|        / \
 *     2   2			|       1   5  <- (1 + 5 != 3)
 * 
 * 
 * Approach (Optimzed)
 * TC : O(n) | SC : O(n)
 * ----------------------------
 * 
 * The idea behind the approch is simple. In the naive
 * approach we were using a separate getHeight() function
 * to get the height of the a particular subtree and then
 * suitable checks were made. 
 * 
 * Here we will use a single function that will return the
 * height of each subtree (left and right) and we will check
 * the difference. If the difference is greater than 1, which
 * state that the tree is un-balanced, the function return
 * -1. Since this is basically a modified getHeight() function,
 * so the height of a tree cannot be -1 and hence we get our 
 * answer.
 **/

#include "tree.h"

int isBalanced(Node *root)
{
	if(root == nullptr)
		return 0;

	// recursively getting the height of left subtree
	int leftHeight = isBalanced(root->lchild);
	
	// if the returned height is -1, then we know,
	// somewhere in the tree, an unbalanced subtree 
	// exits and we return -1.
	if(leftHeight == -1)
		return -1;

	// same goes for the right subtree
	int rightHeight = isBalanced(root->rchild);
	if(rightHeight == -1)
		return -1;

	// Actual checking for the balanced tree.
	// If the left and right height of a current node
	// is positive, then we check for the balancing critera. 
	if(abs(leftHeight - rightHeight) > 1)
		return -1;

	// finally returning the height to the respective callers.
	return max(leftHeight, rightHeight) + 1;
}


int main()
{
	Node *root = create();
	if(isBalanced(root) != -1)
		cout << "Balanced\n";
	else
		cout << "Un-Balanced\n";

	return 0;
}