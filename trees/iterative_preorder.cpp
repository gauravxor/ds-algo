#include "tree.h"
#include <stack>

int main()
{
	Node * root = create();

	stack<Node *>st;

	cout << "The preorder traversal of the tree is \n";
	while(root!= nullptr || st.empty() == false)
	{
		if(root != nullptr)
		{
			cout << root->data << " ";
			st.push(root);
			root = root->lchild;
		}
		else
		{
			root = st.top()->rchild;
			st.pop();
		}
	}
	cout << "\n";
	return 0;
}