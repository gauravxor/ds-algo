#include "binary_tree.h"
#include <algorithm>

void fillPath(Node *root, int node, vector<int> &path, vector<int> temp) {
    if(root == nullptr || path.size() != 0) {
        return;
    }
    if(root->data == node) {
        temp.push_back(root->data);
        path = temp;
        return;
    }

    temp.push_back(root->data);
    fillPath(root->left, node, path, temp);
    fillPath(root->right, node, path, temp);
}

int getLca(Node *root, int node1, int node2) {
    vector<int> path1;
    vector<int> path2;
    fillPath(root, node1, path1, {});
    fillPath(root, node2, path2, {});

    if(path1.size() > path2.size()) {
        swap(path1, path2);
    }
    for(int i = path1.size() - 1; i >= 0; i--) {
        int j = path2.size() - 1;
        while(j >= 0) {
            if(path2[j] == path1[i]) {
                return path2[j];
            }
            j--;

        }
    }
    return -1;
}

int main () {
    Node *rootNode = createTree();
    int firstNode = 0, secondNode = 0;
    cout << "Enter two nodes\n";
    cin >> firstNode >> secondNode;

    int lca = getLca(rootNode, firstNode, secondNode);
    cout << "LCA = " << lca << "\n";
    freeMemory(rootNode);
}