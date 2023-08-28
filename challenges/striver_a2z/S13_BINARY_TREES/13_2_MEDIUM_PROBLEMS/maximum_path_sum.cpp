/**
 *  Code to find the maximum path sum of a binary tree. Mark that the node values are integers
**/

#include "binary_tree.h"


int getSum(Node *root) {
    if(root == nullptr) {
        return 0;
    }

    int leftSum = max(getSum(root->left), 0);
    int rightSum = max(getSum(root->right), 0);

    return max(leftSum, rightSum) + root->data;
}


void findMaxSum(Node *root, int &sum) {
    if(root == nullptr) {
        return;
    }

    int leftSubtreeMaxSum = max(getSum(root->left), 0);
    int rightSubtreeMaxSum = max(getSum(root->right), 0);

    sum = max(sum, leftSubtreeMaxSum + rightSubtreeMaxSum + root->data);

    findMaxSum(root->left, sum);
    findMaxSum(root->right, sum);
}

int main () {
    Node *rootNode = createTree();
    int maxSum = 0;
    findMaxSum(rootNode, maxSum);
    cout << "Max Sum = " << maxSum << "\n";
    freeMemory(rootNode);
    return 0;
}