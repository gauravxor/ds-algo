#include "binary_tree.h"
#include <climits>

int main () {
    Node *rootNode = createTree();
    queue<pair<Node*, int>> q;
    q.push({rootNode, 0});
    int maxWidth = 1;
    while(!q.empty()) {
        int levelSize = q.size();
        int leftIndex = 0, rightIndex = 0;
        for(int i = 0; i < levelSize; i++) {
            Node *currentNode = q.front().first;
            int currentIndex = q.front().second;

            if(i == 0) {
                leftIndex = currentIndex;
            }
            if(i == levelSize - 1) {
                rightIndex = currentIndex;
            }

            if(currentNode->left != nullptr) {
                q.push({currentNode->left, 2 * currentIndex + 1});
            }
            if(currentNode->right != nullptr) {
                q.push({currentNode->right, 2 * currentIndex + 2});
            }
            q.pop();
        }
        maxWidth = max(maxWidth, rightIndex - leftIndex + 1);
    }
    cout << "Max Width = " << maxWidth << "\n";
    freeMemory(rootNode);
    return 0;
}