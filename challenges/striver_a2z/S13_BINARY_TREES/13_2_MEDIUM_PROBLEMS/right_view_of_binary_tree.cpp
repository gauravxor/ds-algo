#include "binary_tree.h"
/** Iterative Approach */
void getRightView(Node *root, vector<int> &rightView) {
    if(root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(q.size() != 0) {
        int levelSize = q.size();
        while(levelSize) {
            if(levelSize == 1) {
                rightView.push_back(q.front()->data);
            }
            if(q.front()->left != nullptr) {
                q.push(q.front()->left);
            }
            if(q.front()->right != nullptr) {
                q.push(q.front()->right);
            }
            q.pop();
            levelSize--;
        }
    }
}

/** Recursive Approach */
void getRightView_2(Node *root, vector<int> &rightView, int maxHeight ) {
    if(root == nullptr) {
        return;
    }
    if(rightView.size() == maxHeight) {
        rightView.push_back(root->data);
    }
    getRightView_2(root->right, rightView, maxHeight + 1);
    getRightView_2(root->left, rightView, maxHeight + 1);
}

int main () {
    Node *rootNode = createTree();
    vector<int> rightView;
    // getRightView(rootNode, rightView);
    getRightView_2(rootNode, rightView, 0);
    freeMemory(rootNode);
    for(int i : rightView) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}