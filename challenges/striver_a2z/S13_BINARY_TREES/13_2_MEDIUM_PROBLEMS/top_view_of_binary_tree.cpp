#include "binary_tree.h"
#include <queue>
#include <unordered_set>
#include <map>
void getTopView(Node *root, vector<int> &topView) {
    if(root == nullptr) {
        return;
    }

    queue<pair<Node*, int>> q;
    map<int, int> mp;

    q.push({root, 0});

    while(!q.empty()) {
        int currentLevelSize = q.size();

        while(currentLevelSize--) {

            Node* currentNode = q.front().first;
            int currentCol = q.front().second;
            q.pop();

            if(mp.find(currentCol) == mp.end()) {
                mp[currentCol] = currentNode->data;
            }

            if(currentNode->left != nullptr) {
                q.push({currentNode->left, currentCol - 1});
            }
            if(currentNode->right != nullptr) {
                q.push({currentNode->right, currentCol + 1});
            }
        }
    }

    for(auto it: mp) {
        topView.push_back(it.second);
    }
}

int main () {
    Node *rootNode = createTree();
    vector<int> topView;
    getTopView(rootNode, topView);

    for(int i : topView) {
        cout << i << " ";
    }
    cout << "\n";
    freeMemory(rootNode);
    return 0;
}