/**
 * Code to generate a binary tree from it's preOrder and
 * inOrder traversal.
 *
 * Given two arrays containing the inorder and preorder 
 * traversal of a binary tree. We need to construct the
 * original binary tree from the given information.
 *	 
 * 
 * NOTE : 
 * 1) We can construct a binary tree only when inorder
 * or postorder traversal is given along with preorder
 * traversal. 
 * 2) In a given node of InOrder traversal, the left and 
 * right portions represent the left and right half of the
 * main binary tree.
 * Eg., if the inorder traversal is [1,2,3,4], then if we 
 * consider the element 3, then the elements present at the 
 * left of 3 are also present at the left portion of original
 * BT and so does it's right potion.
 * 
 * 
 * Approach : Recursive
 * TC : O(n) | SC : O(n)
 * ------------------------
 * 
 * i) One by one pick all the elements from the preOrder traversal and 
 * make it the root node. 
 * 
 * ii) Now search for it's position in the inOrder traversal and mark it.
 * 
 * iii) Recursively call for the left and right subparts, where each recursive
 * call will have specified ranged index for left and right subparts.
 * 
 * 
 * This approach will first generate the left subtree completely then it will 
 * move towards the construction of right subtree.
 */



#include "tree.h"

static int preIndex = 0;
Node * generate(int *inorder, int *preorder, int start, int end)
{
	// base case, this comes in handly when the a node doesnot 
	// have any left or right subtree.
	if(start > end)
		return nullptr;

	// make the root of every recursive calls equal to the next
	// element present in the preOrder traversal.
	Node *root = new Node(preorder[preIndex++]);


	// searching for the element in inOrder traversal.
	int rootPos = 0;
	for(int i = start; i <= end; i++)
	{
		if(root->data == inorder[i])
		{
			rootPos = i;
			break;
		}
	}
	// at this point we have the index of the root element, from the
	// inorder traversal. We will now again call the generate() function
	// for the left and right subtree respectively.

	// recursive call to generate the left subtree of the currentNode
	root->lchild = generate(inorder, preorder, start, rootPos - 1);

	// recursive call to generate the right subtree of the currentNode
	root->rchild = generate(inorder, preorder, rootPos + 1, end);

	return root;
}

int main()
{
	cout << "Enter the number of nodes\n";
	int n;
	cin >> n;
	int inorder[n];
	int preorder[n];

	cout << "Enter the inorder traversal of the tree\n";
	for(int i = 0; i < n; i++)
		cin >> inorder[i];

	cout << "Enter the preorder traversal of the tree\n";
	for(int i = 0; i < n; i++)
		cin >> preorder[i];


	int start = 0;
	int end = n - 1;
	int index = 0;
	Node * root = generate(inorder, preorder, start, end);
	
	cout << "The output tree is\n";
	printLevelWise(root);
	cout << "\n";
	return 0;
}