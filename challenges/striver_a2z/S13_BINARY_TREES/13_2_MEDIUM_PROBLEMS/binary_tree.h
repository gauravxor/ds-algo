#include <iostream>
#include <queue>

using namespace std;
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node () {
        data = 0;
        left = right = nullptr;
    }

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }

    Node(int data, Node *left, Node *right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

Node* createTree() {
    Node *rootNode = nullptr;
    cout << "Enter the data of root node\n";
    int rootData;
    cin >> rootData;
    rootNode = new Node(rootData);
    queue<Node *> q;
    q.push(rootNode);
    int childData;

    vector<int> inputData;
    inputData.push_back(rootData);

    while(!q.empty()) {
        Node *currentNode = q.front();
        q.pop();
        cout << "Enter the left child of " << currentNode->data << ", -1 to skip\n";
        cin >> childData;
        inputData.push_back(childData);
        if(childData != -1) {
            currentNode->left = new Node(childData);
            q.push(currentNode->left);
        }
        cout << "Enter the right child of " << currentNode->data << ", -1 to skip\n";
        cin >> childData;
        inputData.push_back(childData);
        if(childData != -1) {
            currentNode->right = new Node(childData);
            q.push(currentNode->right);
        }
    }

    cout << "\nInput Data\n";
    for(int i : inputData) {
        cout << i << " ";
    }
    cout << "\n";
    return rootNode;
}

void printLevelOrder(Node *rootNode) {
    queue<Node *> q;
    q.push(rootNode);

    while(!q.empty()) {
        Node *currentNode = q.front();
        q.pop();
        cout << currentNode->data << " ";
        if(currentNode->left != nullptr) {
            q.push(currentNode->left);
        }
        if(currentNode->right != nullptr) {
            q.push(currentNode->right);
        }
    }
    cout << "\n";
}

void freeMemory(Node *rootNode) {
    if(rootNode == nullptr) {
        return;
    }
    freeMemory(rootNode->left);
    freeMemory(rootNode->right);
    delete(rootNode);
}