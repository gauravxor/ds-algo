/** 
 * Code to check if CHILDREN SUM PROPERTY hold in a given
 * binary tree.
 * 
 * Children Sum Property : If the root of the tree or it's subtree is
 * equal to the sum of the "data" of its left and right child, then
 * children sum property holds for that binary tree.
 * 
 * Assumptions Made : If any child is NULL, then it's data is taken 0.
 * 
 * 
 * Approach : Recursive
 * TC : O(n) | SC : O(n)
 * --------------------------
 * 
 * Check for the root and recursively check for its subtrees created 
 * by it's left and right child.
 * 
 * Edge Case : If the left and right child of a given node is NULL,
 * then the property exits.
 **/


#include "tree.h"

bool children_sum(Node * root)
{
	// if the root node itself is NULL
	if(root == nullptr)
		return true;

	// if the left and right child of a node is null, then we take
	// them as 0, so property is satisfied.
	if(root->lchild == nullptr && root->rchild == nullptr)
		return true;

	int sum = 0;

	// if left child exists, take its data
	if(root->lchild != nullptr)
		sum += root->lchild->data;

	// if right child exists, take its data
	if(root->rchild != nullptr)
		sum += root->rchild->data;

	// at this point "sum" is having the sum of left and right child of the Node.
	
	// checking if the root is equal to "sum", and recursively check for it's
	// left and right subtree as well.
	return(root->data == sum && children_sum(root->lchild) && children_sum(root->rchild));

}

int main()
{
	Node * root = create();

	if(children_sum(root) == true)
		cout << "Property Exists\n";
	else
		cout << "Property DoesNot Exists\n";
	return 0;
}