#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int getSubArrays(vector<int> &v, int maxSum) {
    int subArrayCount = 1;
    int subArraySum = 0;

    for(int i = 0; i < v.size(); i++) {
        if(subArraySum + v[i] <= maxSum) {
            subArraySum += v[i];
        }
        else {
            subArraySum = v[i];
            subArrayCount += 1;
        }
    }
    return subArrayCount;
}

int solve(vector<int> &v, int k) {
    int low = *max_element(v.begin(), v.end());
    int high = accumulate(v.begin(), v.end(), 0);

    while(low <= high) {
        int mid = (low + high) / 2;
        int possibleSubArrays = getSubArrays(v, mid);
        if(possibleSubArrays <= k) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}

int main () {
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