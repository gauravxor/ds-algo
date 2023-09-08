#include <vector>
#include "bst.h"
using namespace std;
/** Recursive Approach */
void getFloor(Node *root, int n, int &floor) {
    if(root == nullptr) {
        return;
    }
    if(root->data == n) {
        floor = root->data;
        return;
    }
    if(root->data > n) {
        getFloor(root->left, n, floor);
    }
    else {
        floor = root->data;
        getFloor(root->right, n, floor);
    }
}


/** Iterative approach*/
int getFloor(Node *root, int n) {
    int floor = -1;
    while(root != nullptr) {
        if(root->data == n) {
            return root->data;
        }

        if(root->data > n) {
            root = root->left;
        }
        else {
            floor = root->data;
            root = root->right;

        }
    }
    return floor;
}

int main () {
    Node *root = createTree();
    int n;
    cout << "Enter the number for floor\n";
    cin >> n;

    int floor = -1;
    getFloor(root, n, floor);

    cout << "Floor = " << floor << "\n";
    freeMemory(root);
    return 0;
}