#include "bst.h"


Node *kthSmallest(Node *rootNode, int &k) {
    if(rootNode == nullptr) {
        return nullptr;
    }

    Node *resultNode = kthSmallest(rootNode->left, k);
    if(resultNode != nullptr) {
        return resultNode;
    }
    k--;
    if(k == 0) {
        return rootNode;
    }
    return kthSmallest(rootNode->right, k);
}

int main () {
    Node *rootNode = createTree();
    int k;
    cout << "Enter the value of K\n";
    cin >> k;
    Node *kthSmallestNode = kthSmallest(rootNode, k);
    (kthSmallestNode == nullptr) ? cout << "-1\n" : cout << kthSmallestNode->data << "\n";
    freeMemory(rootNode);
    return 0;
}