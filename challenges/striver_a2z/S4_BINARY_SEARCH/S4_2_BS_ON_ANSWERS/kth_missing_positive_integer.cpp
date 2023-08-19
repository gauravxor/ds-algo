#include <vector>
#include <iostream>

using namespace std;
int solve(vector<int> &v, int k) {
    for(int i : v) {
        if(i <= k) {
            k++;
        }
        else {
            break;
        }
    }
    return k;
}


int solve_optimal(vector<int> &v, int k) {
    int low = 0;
    int high = v.size() - 1;

    while(low <= high) {
        int mid = (low + high) / 2;
        int missingCount = v[mid] - (mid + 1);
        if(missingCount < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return (high + 1) + k;
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(auto &it : v) {
        cin >> it;
    }

    int k;
    cin >> k;
    int ans = solve(v, k);
    cout << ans << "\n";
    return 0;
}