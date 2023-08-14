#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generateCombinations(vector<int> &v, int index, int target, vector<int> c, vector<vector<int>> &ans) {
    if(target == 0) {
        ans.push_back(c);
        return;
    }
    if(index == v.size() || v[index] > target) {
        return;
    }
    c.push_back(v[index]);
    generateCombinations(v, index, target - v[index], c, ans);
    c.pop_back();
    generateCombinations(v, index + 1, target, c, ans);
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(auto &it : v) {
        cin >> it;
    }

    int target;
    cin >> target;

    sort(v.begin(), v.end());
    vector<vector<int>> combinations;
    generateCombinations(v, 0, target, {}, combinations);

    for(auto it: combinations) {
        for(int i : it) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}