#include <vector>
#include "bst.h"

using namespace std;
/** Recursive Approach */
void getCeil(Node *root, int n, int &ceil) {
    if(root == nullptr) {
        return;
    }

    if(root->data == n) {
        ceil = root->data;
        return;
    }

    if(root->data > n) {
        ceil = root->data;
        getCeil(root->left, n, ceil);
    }
    else {
        getCeil(root->right, n, ceil);
    }
}

/** Iterative approach */
int getCeil(Node *root, int n) {
    int ceil = -1;
    if(root == nullptr) {
        return -1;
    }

    while(root != nullptr) {
        if(root->data == n) {
            return root->data;
        }
        if(root->data > n) {
            ceil = root->data;
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    return ceil;
}

int main() {
    Node *rootNode = createTree();
    int n;
    cout << "Enter the number for ceil\n";
    cin >> n;

    int ceil = -1;
    getCeil(rootNode, n, ceil);
    cout << ceil << "\n";
    freeMemory(rootNode);
    return 0;
}