#include "bst.h"
using namespace std;

bool search(Node *root, int key) {
    if(root == nullptr) {
        return false;
    }
    if(root->data == key) {
        return true;
    }
    if(root->data > key) {
        return search(root->left, key);
    }
    else {
        return search(root->right, key);
    }
}

/** Iterative approach */
bool searchItr(Node *root, int key) {
    if (root == nullptr) {
        return false;
    }

    while (root != nullptr) {
        if (root->data == key) {
            return true;
        }
        if (root->data < key) {
            root = root->right;
        }
        else {
            root = root->left;
        }
    }
    return false;
}

int main() {
    Node *rootNode = createTree();
    int key;
    cout << "Enter the key\n";
    cin >> key;

    int result = search(rootNode, key);
    (result) ? cout << "Present\n" : cout << "Not Present\n";
    freeMemory(rootNode);
    return 0;
}