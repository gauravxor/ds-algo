#include "binary_tree.h"

/** Own Approach, (more functional parameters )*/
void getPath(Node *root, vector<int> &path, int target, vector<int> temp) {
    if(root == nullptr || path.size() != 0) {
        return;
    }

    if(root->data == target) {
        temp.push_back(root->data);
        path = temp;
        return;
    }
    temp.push_back(root->data);
    getPath(root->left, path, target, temp);
    getPath(root->right, path, target, temp);
}

/** Better Approach with less functional parameters */
bool getPath(Node *root, vector<int> &path, int target) {
    if(root == nullptr) {
        return false;
    }
    path.push_back(root->data);

    if(root->data == target) {
        return true;
    }

    bool isTargetPresentInLeft = getPath(root->left, path, target);
    if(isTargetPresentInLeft == true) {
        return true;
    }
    bool isTargetPresentInRight = getPath(root->right, path, target);
    if(isTargetPresentInRight == true) {
        return true;
    }
    path.pop_back();
    return false;


}
int main () {
    Node *rootNode = createTree();
    cout << "Enter the target node\n";
    int target;
    cin >> target;

    vector<int> path;
    // getPath(rootNode, path, target, {});
    getPath(rootNode, path, target);
    freeMemory(rootNode);
    for(int i : path) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}