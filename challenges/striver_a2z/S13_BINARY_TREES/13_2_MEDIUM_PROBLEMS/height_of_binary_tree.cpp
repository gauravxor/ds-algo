#include "binary_tree.h"

int getHeight(Node *rootNode) {
    /** If the current node is itself empty, then we know that it has no height so we return 0 */
    if(rootNode == nullptr) {
        return 0;
    }

    /** Recrusively get the height of left sub tree */
    int leftHeight = getHeight(rootNode->left);

    /** Recrusively get the height of right sub tree */
    int rightHeight = getHeight(rootNode->right);

    /** Now take the max of the heights of left and right subtrees
     *  Add 1 to the max value, we have the height of left and right subtrees, where the
     *  the parent(root) is not included, so to include it in the height calculation we add
     *  extra 1 to the answer.
     */
    return max(leftHeight, rightHeight) + 1;
}

int main() {
    Node *rootNode = createTree();
    int height = getHeight(rootNode);
    freeMemory(rootNode);
    cout << "Height = " << height << "\n";
    return 0;
}