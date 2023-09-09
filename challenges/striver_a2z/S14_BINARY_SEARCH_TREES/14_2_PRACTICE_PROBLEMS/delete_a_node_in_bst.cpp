#include "bst.h"
#include <vector>
using namespace std;

Node *arrange(Node *rootNode) {
    if (rootNode->left == nullptr) {
        Node *nodeToReturn = rootNode->right;
        delete (rootNode);
        return nodeToReturn;
    }

    if (rootNode->right == nullptr) {
        Node *nodeToReturn = rootNode->left;
        delete (rootNode);
        return nodeToReturn;
    }

    Node *nodeToReturn = rootNode->right;
    Node *leftSubTreeNode = rootNode->left;
    Node *rightSubTreeNode = rootNode->right;

    while (rightSubTreeNode != nullptr && rightSubTreeNode->left != nullptr) {
        rightSubTreeNode = rightSubTreeNode->left;
    }

    rightSubTreeNode->left = leftSubTreeNode;
    delete (rootNode);
    return nodeToReturn;
}

Node *deleteNode(Node *rootNode, int key) {
    if (rootNode == nullptr) {
        return nullptr;
    }

    if (rootNode->data == key) {
        return arrange(rootNode);
    }

    bool isLeft = false;
    Node *previousNode = rootNode, *tempRoot = rootNode;

    while (rootNode != nullptr) {
        if (rootNode->data == key) {
            if (isLeft == false) {
                previousNode->right = arrange(rootNode);
            }
            else {
                previousNode->left = arrange(rootNode);
            }
            return previousNode;
        }

        previousNode = rootNode;
        if (rootNode->data > key) {
            rootNode = rootNode->left;
            isLeft = true;
        }
        else {
            rootNode = rootNode->right;
            isLeft = false;
        }
    }
    return tempRoot;
}

int main() {
    Node *rootNode = createTree();
    int node;
    cout << "Enter the node to be deleted\n";
    cin >> node;
    Node *newNode = deleteNode(rootNode, node);
    printTreeData(newNode);
    freeMemory(newNode);
    return 0;
}