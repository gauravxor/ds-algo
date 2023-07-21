#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &v) {
    int prefix = 1, suffix = 1;
    int maxProduct = 0;

    for(int i = 0; i < v.size(); i++) {
        prefix *= v[i];
        suffix *= v[v.size() - i - 1];
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;
        maxProduct = max(maxProduct, max(prefix, suffix));
    }
    return maxProduct;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &it: v)
        cin >> it;

    int maxProduct = solve(v);
    cout << "Max Product = " << maxProduct << "\n";
    return 0;
}