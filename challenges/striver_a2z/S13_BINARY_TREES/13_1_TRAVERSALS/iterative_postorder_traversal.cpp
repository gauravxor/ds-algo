#include "binary_tree.h"
#include <stack>


void iterative_postorder(Node *root) {
    stack<Node*> st;
    Node *previous = nullptr;
    Node *current = root;
    while(current != nullptr || !st.empty()) {
        if(current != nullptr) {
            st.push(current);
            current = current->left;
        }
        else {
            Node * parentNode = st.top();
            if(parentNode->right != nullptr && parentNode->right != previous) {
                current = parentNode->right;
            }
            else {
                cout << parentNode->data << " ";
                previous = parentNode;
                st.pop();
            }
        }
    }
    cout << "\n";
}

/** Postorder means Left->Right->Root, so if we reverse the order we get
 *  Root->Right->Left, so we consider any incoming nodes as the answer and
 *  push it's left and right childs into the stack to process later.
 *
 *  We first push the left child then the right one, so when we take stack's top
 *  right child is fetched first, thereby maintaining the reverse order of postorder
 *  traversal.
 *
 *  TC : O(n)
 *  We will be traversing through all N nodes of the tree.
 *
 *  SC : O(n) + O(n)
 *  O(n) : To store the answer
 *  O(n) : Stack space
 */
void interative_postorder_2(Node *root) {
    stack<Node*> st;
    st.push(root);

    vector<int> postorder;

    while(!st.empty()) {
        root = st.top();
        if(root != nullptr) {
            postorder.push_back(root->data);
            if(root->left != nullptr) {
                st.push(root->left);
            }
            if(root->right != nullptr) {
                st.push(root->right);
            }
        }
    }

    for(int i = postorder.size() - 1; i >= 0; i--) {
        cout << postorder[i] << " ";
    }
    cout << "\n";
}

int main () {
    Node* rootNode = createTree();
    iterative_postorder(rootNode);
    freeMemory(rootNode);
    return 0;
}