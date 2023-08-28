#include "binary_tree.h"
#include <stack>

void iterative_inorder(Node *root) {
    stack<Node*> st;
    while(true) {
        if(root != nullptr) {
            st.push(root);
            root = root->left;
        }
        else {
            if(st.empty()) {
                break;
            }
            root = st.top();
            cout << root->data << " ";
            st.pop();
            root = root->right;
        }
    }
    cout << "\n";
}

int main () {
    Node* rootNode = createTree();
    iterative_inorder(rootNode);
    freeMemory(rootNode);
    return 0;
}