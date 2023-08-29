#include "binary_tree.h"


bool isSymmetric(Node *lTree, Node *rTree) {
    if(lTree == nullptr || rTree == nullptr) {
        return (lTree == rTree);
    }

    if(lTree->data != rTree->data) {
        return false;
    }

    bool leftRes = isSymmetric(lTree->left, rTree->right);
    if(leftRes == false) {
        return false;
    }

    bool rightRes = isSymmetric(lTree->right, rTree->left);
    if(rightRes == false) {
        return false;
    }

    return true;
}

bool checkSymmetric(Node *root) {
    if(root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        return true;
    }
    return isSymmetric(root->left, root->right);
}

int main () {
    Node *rootNode = createTree();
    (checkSymmetric(rootNode)) ? cout << "YES\n" : cout << "NO\n";
    freeMemory(rootNode);
    return 0;
}