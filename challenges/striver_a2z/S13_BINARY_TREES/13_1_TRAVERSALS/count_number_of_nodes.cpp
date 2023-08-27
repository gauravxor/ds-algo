#include "binary_tree.h"

using namespace std;

int countNodes(Node *rootNode) {
    if(rootNode == nullptr) {
        return 0;
    }
    int leftSubtreeNodes = countNodes(rootNode->left);
    int rightSubtreeNodes = countNodes(rootNode->right);

    return 1 + leftSubtreeNodes + rightSubtreeNodes;
}

int main() {
    Node *treeNode = createTree();
    int nodes = countNodes(treeNode);
    freeMemory(treeNode);
    cout << "Number of nodes = " << nodes << "\n";
    return 0;
}