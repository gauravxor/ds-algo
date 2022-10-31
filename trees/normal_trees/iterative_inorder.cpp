#include "tree.h"
#include <stack>

int main()
{
	Node * root = create();
	Node * temp;
	stack<Node *> st;

	cout << "The inorder traversal of the tree is\n";
	while(root != nullptr || !st.empty())
	{
		if(root != nullptr)
		{
			st.push(root);
			root = root->lchild;
		}
		else
		{	
			root = st.top();
			cout << root->data << " ";
			st.pop();
			root = root->rchild;
		}	
	}
	freeNodes(root);
	cout << "\n";
}