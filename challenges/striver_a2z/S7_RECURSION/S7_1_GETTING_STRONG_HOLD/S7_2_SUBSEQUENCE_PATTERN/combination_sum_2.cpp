#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>
using namespace std;

void generateCombinations(vector<int> &v, int index, int target, vector<int> c, set<vector<int>> &st) {
    if(target == 0) {
        st.insert(c);
        return;
    }
    if(index == v.size() || v[index] > target) {
        return;
    }
    c.push_back(v[index]);
    generateCombinations(v, index + 1, target - v[index], c, st);
    c.pop_back();
    generateCombinations(v, index + 1, target, c, st);
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
    cout << "Sorted\n";
    int sum = accumulate(v.begin(), v.end(), 0);
    if(sum < target) {
        cout << "Not possible\n";
        return 0;
    }
    set<vector<int>> combinations;
    generateCombinations(v, 0, target, {}, combinations);

    for(auto it: combinations) {
        for(int i : it) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}
