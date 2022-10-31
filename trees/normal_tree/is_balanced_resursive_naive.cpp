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
 * Approach (Naive)
 * TC : O(n) | SC : O(n ^ 2)
 * ----------------------------
 * 
 * We use the naive method, where we get the height of
 * each left and right subtree and compare the results.
 * If the difference between the heights is more than 1,
 * we return -1.
 **/

#include "tree.h"

int getHeight(Node *root)
{
	if(root == nullptr)
		return 0;

	int left = getHeight(root->lchild) + 1;
	int right = getHeight(root->rchild) + 1;

	return max(left, right);
}


int isBalanced(Node *root)
{
	if(root == nullptr)
		return 0;

	int lh = getHeight(root->lchild);
	int rh = getHeight(root->rchild);

	// checking the difference of left and right height for current node and
	// recursively checking for the left and right subtree as well.
	return(abs(lh - rh) <= 1 && isBalanced(root->lchild) && isBalanced(root->rchild));
}


int main()
{
	Node *root = create();
	if(isBalanced(root))
		cout << "Balanced\n";
	else
		cout << "Un-Balanced\n";

	return 0;
}