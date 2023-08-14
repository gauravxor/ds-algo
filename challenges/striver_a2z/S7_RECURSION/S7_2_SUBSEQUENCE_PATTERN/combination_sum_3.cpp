#include <iostream>
#include <vector>

using namespace std;

void generateSubsets(int start, int target, int size, vector<int> temp, vector<vector<int>> &ans) {
    if(target == 0 && size == 0) {
        ans.push_back(temp);
        return;
    }
    if(start > 9 || start > target) {
        return;
    }

    temp.push_back(start);
    generateSubsets(start + 1, target - start, size - 1, temp, ans);
    temp.pop_back();
    generateSubsets(start + 1, target, size, temp, ans);
}

int main() {
    int n, size;
    cin >> n >> size;

    vector<vector<int>> subsets;
    generateSubsets(1, n, size, {}, subsets);

    cout << "The subsets are\n";
    for(auto it : subsets) {
        for(int i : it) {
            cout << i << " ";
        }
        cout << "\n";
    }
}