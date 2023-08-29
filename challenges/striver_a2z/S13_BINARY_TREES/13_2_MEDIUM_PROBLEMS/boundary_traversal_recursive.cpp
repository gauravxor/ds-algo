/** Code to print the boundary traversal of a tree in anticlockwise manner */

#include "binary_tree.h"

void traverseLeftNodes(Node *root, vector<int> &ans) {
    /** Check if the node is not null and is not a lef node. */
    if(root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        return;
    }

    ans.push_back(root->data);

    /** If the current node has something on the left, then we need to process it, otherwise try out it's right nodes */
    if(root->left != nullptr) {
        traverseLeftNodes(root->left, ans);
    }
    else {
        traverseLeftNodes(root->right, ans);
    }
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


void traverseRightNodes(Node *root, vector<int> &ans) {
    if(root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        return;
    }

    ans.push_back(root->data);
    if(root->right != nullptr) {
        traverseRightNodes(root->right, ans);
    }
    else {
        traverseRightNodes(root->left, ans);
    }
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

    vector<int> right;
    traverseRightNodes(root->right, right);
    ans.insert(ans.end(), right.rbegin(), right.rend());
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