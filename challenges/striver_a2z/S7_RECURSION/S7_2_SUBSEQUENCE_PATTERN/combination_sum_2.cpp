#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>
using namespace std;

void generateCombinations(vector<int> &v, int index, int target, vector<int> temp, vector<vector<int>> &ans) {

    if(target == 0) {
        ans.push_back(temp);
        return;
    }

    if(index == v.size() || v[index] > target) {
        return;
    }

    for(int i = index; i < v.size(); i++) {
        if(i != index && v[i] == v[i - 1]) {
            continue;
        }
        if(v[i] > target) {
            return;
        }
        temp.push_back(v[i]);
        generateCombinations(v, i + 1, target - v[i], temp, ans);
        temp.pop_back();
    }
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
