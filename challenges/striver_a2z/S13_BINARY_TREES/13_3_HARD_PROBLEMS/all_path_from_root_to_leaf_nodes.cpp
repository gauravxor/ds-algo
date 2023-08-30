#include "binary_tree.h"
#include <iostream>
#include <vector>

void getPaths(Node *root, vector<int> temp, vector<vector<int>> &paths) {
    if (root == nullptr) {
        return;
    }
    temp.push_back(root->data);
    getPaths(root->left, temp, paths);
    getPaths(root->right, temp, paths);
    if (root->left == nullptr && root->right == nullptr) {
        paths.push_back(temp);
    }
}

int main() {
    Node *rootNode = createTree();
    vector<vector<int>> paths;
    getPaths(rootNode, {}, paths);
    freeMemory(rootNode);

    for (auto path : paths) {
        for (int i : path) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}