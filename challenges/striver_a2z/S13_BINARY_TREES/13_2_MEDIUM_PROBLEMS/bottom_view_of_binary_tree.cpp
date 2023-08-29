#include "binary_tree.h"

#include <queue>
#include <vector>
#include <map>
void getBottomView(Node *root, vector<int> &ans) {
    if(root == nullptr) {
        return;
    }
    queue<pair<Node*, int>> q;
    map<int, int> mp;
    q.push({root, 0});

    while(q.size() != 0) {
        Node *curr = q.front().first;
        int col = q.front().second;
        q.pop();

        mp[col] = curr->data;

        if(curr->left != nullptr) {
            q.push({curr->left, col - 1});
        }
        if(curr->right != nullptr) {
            q.push({curr->right, col + 1});
        }
    }

    for(auto it : mp) {
        ans.push_back(it.second);
    }
}


int main () {
    Node *rootNode = createTree();
    vector<int> ans;
    getBottomView(rootNode, ans);
    freeMemory(rootNode);

    for(int i : ans) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}