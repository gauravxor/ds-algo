#include "bst.h"
#include <vector>

using namespace std;

Node* insertNode(Node *root, int n) {
    Node *newNode = new Node(n);
    if(root == nullptr) {
        return newNode;
    }
    Node *tempRoot = root;
    while(root != nullptr) {
        if(root->data < n) {
            if(root->right == nullptr) {
                root->right = newNode;
                return tempRoot;
            }
            root = root->right;
        }
        else {
            if(root->left == nullptr) {
                root->left = newNode;
                return tempRoot;
            }
            root = root->left;
        }
    }
    return tempRoot;
}


int main() {
    Node *root = createTree();
    int n;
    cout << "Enter the value to be inserted\n";
    cin >> n;

    Node *newRoot = insertNode(root, n);
    cout << "Node inserted\n";
    printTreeData(newRoot);
    freeMemory(newRoot);
    // freeMemory(root);
    return 0;
}