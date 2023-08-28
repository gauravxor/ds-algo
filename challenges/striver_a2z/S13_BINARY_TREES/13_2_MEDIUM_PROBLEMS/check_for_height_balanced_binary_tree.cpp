/**
 * A binary tree whose height of left and right subtree does not differ by more than 1,
 *  is called a height balanced binary tree.
**/

#include "binary_tree.h"
bool checkIfHeightBalanced(Node *root) {
    if(root == nullptr) {
        return true;
    }

    /** Recursively get the height of left subtree */
    int leftSubtreeHeight = getHeight(root->left);

    /** Recursively get the height of right subtree */
    int rightSubtreeHeight = getHeight(root->right);

    /** If height balancing condition fails, we dont need to make more recursive calls so we return */
    if(abs(leftSubtreeHeight - rightSubtreeHeight) > 1) {
        return false;
    }

    /** If the current node is height balanced, then subsequently check for it's left substree */
    bool isLeftSubtreeBalanced = checkIfHeightBalanced(root->left);
    if(isLeftSubtreeBalanced == false) {
        return false;
    }

    /** If the current node is height balanced, then subsequently check for it's right substree */
    bool isRightSubtreeBalanced = checkIfHeightBalanced(root->right);
    if(isRightSubtreeBalanced == false) {
        return false;
    }

    /** If both left and right substrees are height balanced, return true. */
    return true;
}


int main () {
    Node *rootNode = createTree();
    cout << "Height of whole BT = " << getHeight(rootNode) << "\n";
    int isHeightBalanced = checkIfHeightBalanced(rootNode);
    (isHeightBalanced) ? cout << "YES\n" : cout << "NO\n";
    freeMemory(rootNode);
    return 0;
}