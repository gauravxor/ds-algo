#include <iostream>
#include <queue>

using namespace std;
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node() {
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

Node *createTree() {
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

    while (!q.empty()) {
        Node *currentNode = q.front();
        q.pop();
        cout << "Enter the left child of " << currentNode->data << ", -1 to skip\n";
        cin >> childData;
        inputData.push_back(childData);
        if (childData != -1) {
            currentNode->left = new Node(childData);
            q.push(currentNode->left);
        }
        cout << "Enter the right child of " << currentNode->data << ", -1 to skip\n";
        cin >> childData;
        inputData.push_back(childData);
        if (childData != -1) {
            currentNode->right = new Node(childData);
            q.push(currentNode->right);
        }
    }

    cout << "\nInput Data\n";
    for (int i : inputData) {
        cout << i << " ";
    }
    cout << "\n";
    return rootNode;
}

void printLevelOrder(Node *rootNode) {
    queue<Node *> q;
    q.push(rootNode);

    while (!q.empty()) {
        Node *currentNode = q.front();
        q.pop();
        cout << currentNode->data << " ";
        if (currentNode->left != nullptr) {
            q.push(currentNode->left);
        }
        if (currentNode->right != nullptr) {
            q.push(currentNode->right);
        }
    }
    cout << "\n";
}

void freeMemory(Node *rootNode) {
    if (rootNode == nullptr) {
        return;
    }
    freeMemory(rootNode->left);
    freeMemory(rootNode->right);
    delete (rootNode);
}

int getHeight(Node *rootNode) {
    if (rootNode == nullptr) {
        return 0;
    }

    int leftSubtreeHeight = 1 + getHeight(rootNode->left);
    int rightSubtreeHeight = 1 + getHeight(rootNode->right);

    return max(leftSubtreeHeight, rightSubtreeHeight);
}

void printTreeData(Node *rootNode) {
    vector<int> treeData;
    if (rootNode == nullptr) {
        return;
    }

    queue<Node *> q;
    q.push(rootNode);
    treeData.push_back(rootNode->data);

    while (q.size() != 0) {
        Node *front = q.front();
        q.pop();
        treeData.push_back((front->left == nullptr) ? -1 : front->left->data);
        treeData.push_back((front->right == nullptr) ? -1 : front->right->data);
        if (front->left != nullptr)
            q.push(front->left);
        if (front->right != nullptr)
            q.push(front->right);
    }

    cout << "The tree data is\n";
    for (int i : treeData) {
        cout << i << " ";
    }
    cout << "\n";
}