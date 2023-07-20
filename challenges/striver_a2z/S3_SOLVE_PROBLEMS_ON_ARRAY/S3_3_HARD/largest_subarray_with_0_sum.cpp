#include <iostream>
#include <vector>
#include <map>
using namespace std;


int solve(vector<int> &v) {
    map<int, int> mp;
    int prefixSum = 0, maxLength = 0;
    for(int i = 0; i < v.size(); i++) {
        prefixSum += v[i];
        if(prefixSum == 0)
            maxLength = i + 1;
        else {
            if(mp.find(prefixSum) != mp.end())
                maxLength = max(maxLength, i - mp[prefixSum]);
            else
                mp[prefixSum] = i;
        }
    }
    return maxLength;
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(auto &it : v)
        cin >> it;

    int maxSubarray = solve(v);
    cout << "Max subarray with 0 sum = " << maxSubarray << "\n";
    return 0;
}