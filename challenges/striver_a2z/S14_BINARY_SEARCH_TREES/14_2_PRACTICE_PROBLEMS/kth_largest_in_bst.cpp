#include "bst.h"


Node *kthLargest(Node *rootNode, int &k) {
    if(rootNode == nullptr) {
        return nullptr;
    }

    Node *resultNode = kthLargest(rootNode->right, k);
    if(resultNode != nullptr) {
        return resultNode;
    }
    k--;
    if(k == 0) {
        return rootNode;
    }
    return kthLargest(rootNode->left, k);
}

int main () {
    Node *rootNode = createTree();
    int k;
    cout << "Enter the value of K\n";
    cin >> k;
    Node *kthSmallestNode = kthLargest(rootNode, k);
    (kthSmallestNode == nullptr) ? cout << "-1\n" : cout << kthSmallestNode->data << "\n";
    freeMemory(rootNode);
    return 0;
}