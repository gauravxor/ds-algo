#include "binary_tree.h"

/** Recursive Approach */
void getLeftView(Node *root, vector<int> &leftView, int height, int &maxHeight) {
    if(root == nullptr) {
        return;
    }
    if(height > maxHeight) {
        leftView.push_back(root->data);
        maxHeight = height;
    }
    getLeftView(root->left, leftView, height + 1, maxHeight);
    getLeftView(root->right, leftView, height + 1, maxHeight);
}

/** Iterative Approach */
void getLeftView_2(Node *root, vector<int> &leftView) {
    if(root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);
    while(q.size() != 0) {
        int levelSize = q.size();
        leftView.push_back(q.front()->data);
        while(levelSize--) {
            Node *curr = q.front();
            q.pop();
            if(curr->left != nullptr) {
                q.push(curr->left);
            }
            if(curr->right != nullptr) {
                q.push(curr->right);
            }
        }
    }
}

int main () {
    Node *rootNode = createTree();
    vector<int> leftView;
    int maxHeight = -1;
    // getLeftView(rootNode, leftView, 0, maxHeight);
    getLeftView_2(rootNode, leftView);
    freeMemory(rootNode);

    cout << "Left View\n";
    for(int i : leftView) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}