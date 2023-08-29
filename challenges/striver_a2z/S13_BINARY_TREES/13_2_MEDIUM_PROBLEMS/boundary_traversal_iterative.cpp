/**
 * Code to print the boundary traversal of a tree in anticlockwise manner
 * This is an optimal approach, as it removes the recursive stack space while
 * travering the left and right side of the tree.
**/

#include "binary_tree.h"

void traverseLeftNodes(Node *root, vector<int> &ans) {
    /** Check if the node is not null and is not a lef node. */
    if(root == nullptr) {
        return;
    }
    while(root != nullptr) {
        if(root->left != nullptr || root->right != nullptr) {
            ans.push_back(root->data);
        }
        root = (root->left != nullptr) ? root->left : root ->right;
    }
}

void traverseRightNodes(Node *root, vector<int> &ans) {
    if(root == nullptr) {
        return;
    }
    vector<int> right;

    while(root != nullptr) {
        if(root->left != nullptr || root->right != nullptr) {
            right.push_back(root->data);
        }
        root = (root->right != nullptr) ? root->right : root ->left;
    }
    ans.insert(ans.end(), right.rbegin(), right.rend());
}

void traverseLeafNodes(Node *root, vector<int> &ans) {
    if(root == nullptr) {
        return;
    }
    if(root->left == nullptr && root->right == nullptr) {
        ans.push_back(root->data);
    }
    traverseLeafNodes(root->left, ans);
    traverseLeafNodes(root->right, ans);
}

void traverseBoundary(Node *root, vector<int> &ans) {
    /** Check if the tree is empty */
    if(root == nullptr) {
        return;
    }
    if(root->left != nullptr || root->right != nullptr) {
        ans.push_back(root->data);
    }
    traverseLeftNodes(root->left, ans);
    traverseLeafNodes(root, ans);

    traverseRightNodes(root->right, ans);
}

int main () {
    Node *rootNode = createTree();
    vector<int> boundary;
    traverseBoundary(rootNode, boundary);

    for(int i : boundary) {
        cout << i << " ";
    }
    cout << "\n";
    freeMemory(rootNode);
    return 0;

}