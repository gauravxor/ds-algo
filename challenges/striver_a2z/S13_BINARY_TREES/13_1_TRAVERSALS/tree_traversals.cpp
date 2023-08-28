/**
 * Code to print all the three traversals of a binary tree.
 * 1) In Order -> Left Root Right
 * 2) Pre Order -> Root Left Right
 * 3) Post Order -> Left Right Root
*/
#include "binary_tree.h"

void inorder(Node *rootNode) {
    if(rootNode == nullptr) {
        return;
    }
    inorder(rootNode->left);
    cout << rootNode->data << " ";
    inorder(rootNode->right);
}

void preorder(Node *rootNode) {
    if(rootNode == nullptr) {
        return;
    }
    cout << rootNode->data << " ";
    preorder(rootNode->left);
    preorder(rootNode->right);
}

void postorder(Node *rootNode) {
    if(rootNode == nullptr) {
        return;
    }
    postorder(rootNode->left);
    postorder(rootNode->right);
    cout << rootNode->data << " ";
}

int main () {
    Node *treeNode = createTree();
    inorder(treeNode);
    cout << "\n";
    preorder(treeNode);
    cout << "\n";
    postorder(treeNode);
    cout << "\n";
    freeMemory(treeNode);
    return 0;
}