/**
 * Code to convert a Binary tree to a Doubly Linked List.
 * 
 * Given a binary tree, we need to generate a DLL of the
 * inorder traversal of the BT, where the left and right
 * node pointer of the tree will be the previous and 
 * next node pointer of the DLL.
 * 
 * 
 * Approach : Recursive
 * TC : O(n) | SC : O(n)
 * -----------------------
 * 
 * Recursively keep checking for the left node. As soon as we
 * reach an end, check if we are dealing with the first node
 * of the DLL. If so then assign the head or else adjust the
 * previous and next pointers accordingly.
 * 
 * Finally assign the previous pointer to the most recent node
 * and recursively process the right subtree and return the head
 * of the DLL.
 * 
 * 
 * NODE :  The task is done according to inOrder Traversal. In 
 * simple terms, while doing inorder traversal using recursion,
 * we do the following three steps.
 * i)  Traverse the left subtree.
 * ii) If an end is reached then print the data.
 * iii)Again traverse the right subtree.
 * 
 * In this approach, in place of the 2nd step, we are handling the
 * pointers for the DLL, nothing else. 
 **/


#include "tree.h"

static Node *previous = nullptr;
Node* bt_to_dll(Node *root)
{
	if(root == nullptr)
		return root;

	Node *head = bt_to_dll(root->lchild);
	if(previous == nullptr)
		head = root;
	else
	{
		previous->rchild = root;
		root->lchild = previous;
	}
	previous = root;
	bt_to_dll(root->rchild);
	return head;
}

Node* print(Node *head)
{
	while(head != nullptr)
	{
		cout << head->data << " ";
		if(head->rchild == nullptr)
			break;
		head = head->rchild;
	}
	return head;
}

void reversePrint(Node *head)
{
	while(head != nullptr)
	{
		cout << head->data << " ";
		head = head->lchild;
	}
	cout << "\n";
}


int main()
{
	Node *root = create();

	cout << "The given input is\n";
	printLevelWise(root);
	cout << "\n";

	Node * head = bt_to_dll(root);
	Node* lastNode = print(head);
	cout << "\n";
	reversePrint(lastNode);
	return 0;
}