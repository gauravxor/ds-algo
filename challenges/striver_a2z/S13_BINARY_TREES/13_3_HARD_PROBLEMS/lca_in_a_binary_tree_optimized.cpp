#include "binary_tree.h"

int getLca(Node *root, int target_1, int target_2) {
    if(root == nullptr) {
        return -1;
    }
    if(root->data == target_1 || root->data == target_2) {
        return root->data;
    }

    int leftSubtreeLca = getLca(root->left, target_1, target_2);
    int rightSubtreeLca = getLca(root->right, target_1, target_2);

    if(leftSubtreeLca == -1) {
        return rightSubtreeLca;
    }
    else
    if(rightSubtreeLca == -1) {
        return leftSubtreeLca;
    }
    else {
        return root->data;
    }
}

int main () {
    Node *rootNode = createTree();

    int target_1 = 0, target_2 = 0;
    cout << "Enter the target nodes\n";
    cin >> target_1 >> target_2;
    int lca = getLca(rootNode, target_1, target_2);
    cout << "LCA = " << lca << "\n";
    freeMemory(rootNode);
    return 0;
}