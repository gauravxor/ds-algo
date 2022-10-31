/**
 *  Program to find the height of a binary tree using recursion.
 * 
 *  The idea is to find the height of the left child of a node,
 *  then find the height of the left child of a node and select the
 *  maximum hight between them.
**/


#include "tree.h"
int getHeight(Node * root)
{
	if(root == nullptr)
		return 0;

	int l = getHeight(root->lchild) + 1;	
	int r = getHeight(root->rchild) + 1;
	
	return max(l, r);
}


int main()
{
	Node * root = create();
	int height = getHeight(root);

	cout << "The height of the tree is " << height << "\n";
	return 0;
}
