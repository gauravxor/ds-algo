#include "binary_tree.h"
#include <map>
#include <set>
#include <queue>
void verticalOrderTraversal(Node *root, vector<vector<int>> &ans) {
    if(root == nullptr) {
        return;
    }

    map<int, map<int, multiset<int>>> mp;
    queue<pair<Node*, pair<int, int>>> q;
    q.push({root, {0, 0}});

    while(!q.empty()) {
        auto curr = q.front();
        q.pop();

        int data = curr.first->data;
        int row = curr.second.second;
        int col = curr.second.first;

        mp[col][row].insert(data);

        if(curr.first->left != nullptr) {
            q.push({curr.first->left,{col - 1, row + 1}});
        }
        if(curr.first->right != nullptr) {
            q.push({curr.first->right,{col + 1, row + 1}});
        }
    }

    for(auto it : mp) {
        vector<int> colData;
        for(auto column : it.second) {
            colData.insert(colData.end(), column.second.begin(), column.second.end());
        }
        ans.push_back(colData);
    }
}

int main () {
    Node *rootNode = createTree();
    vector<vector<int>> ans;
    verticalOrderTraversal(rootNode, ans);

    for(auto it : ans) {
        for(int i : it) {
            cout << i << " ";
        }
        cout << "\n";
    }
    freeMemory(rootNode);
    return 0;
}