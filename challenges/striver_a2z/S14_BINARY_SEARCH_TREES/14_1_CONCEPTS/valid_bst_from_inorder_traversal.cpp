/** If BST is valid, then it's inorder traversal will be a sorted array */
#include <vector>
#include <iostream>
using namespace std;
bool isValid(vector<int> &v) {
    for(int i = 0; i < v.size() - 1; i++) {
        if(v[i] >= v[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &it : v) {
        cin >> it;
    }

    (isValid(v)) ? cout << "Valid\n" : cout << "InValid\n";
    return 0;

}