#include <iostream>
#include <vector>

using namespace std;

void generateSubsets(vector<int> &v, int index, vector<int> temp, vector<vector<int>> &ans) {
    ans.push_back(temp);
    if(index == v.size()) {
        return;
    }

    for(int i = index; i < v.size(); i++) {
        if(i != index && v[i] == v[i - 1]) {
            continue;
        }
        temp.push_back(v[i]);
        generateSubsets(v, i + 1, temp, ans);
        temp.pop_back();
    }
}

int main () {
    int n;
    cin >> n;

    vector<int> v(n);
    for(auto &it : v) {
        cin >> it;
    }

    vector<vector<int>> subsets;
    generateSubsets(v, 0, {}, subsets);

    cout << "The subsets are\n";
    for(auto it : subsets) {
        for(int i : it) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}