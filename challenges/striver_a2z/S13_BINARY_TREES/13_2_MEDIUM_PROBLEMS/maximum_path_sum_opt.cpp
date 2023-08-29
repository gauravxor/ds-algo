/**
 *  Code to find the maximum path sum of a binary tree. Mark that the node values are integers
**/

#include "binary_tree.h"

int findMaxSum(Node *root, int &sum) {
    if(root == nullptr) {
        return 0;
    }

    int leftSubtreeMaxSum = max(findMaxSum(root->left, sum), 0);
    int rightSubtreeMaxSum = max(findMaxSum(root->right, sum), 0);

    sum = max(sum, leftSubtreeMaxSum + rightSubtreeMaxSum + root->data);
    return max(leftSubtreeMaxSum, rightSubtreeMaxSum) + root->data;
}

int main () {
    Node *rootNode = createTree();
    int maxSum = 0;
    findMaxSum(rootNode, maxSum);
    cout << "Max Sum = " << maxSum << "\n";
    freeMemory(rootNode);
    return 0;
}