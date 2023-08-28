#include "binary_tree.h"
#include <stack>


void iterative_preorder(Node *root) {
    stack<Node*> st;
    while(true) {
        if(root != nullptr) {
            cout << root->data << " ";
            st.push(root);
            root = root->left;
        }
        else {
            if(st.empty()) {
                break;
            }
            root = st.top();
            st.pop();
            root = root->right;
        }
    }
    cout << "\n";
}

int main () {
    Node* rootNode = createTree();
    iterative_preorder(rootNode);
    freeMemory(rootNode);
    return 0;
}