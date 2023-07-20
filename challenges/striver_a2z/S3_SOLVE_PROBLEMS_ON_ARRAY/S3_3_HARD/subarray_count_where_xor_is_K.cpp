#include <iostream>
#include <vector>
#include <map>
using namespace std;


int solve(vector<int> &v, int target) {
    map<int, int> mp;

    /* Edge Case when Target = 0 */
    mp[0] = 1;
    int prefixXor = v[0], count = 0;
    for(int i = 0; i < v.size(); i++) {
        prefixXor ^= v[i];
        if(mp.find(prefixXor ^ target) != mp.end())
            count += mp[prefixXor ^ target];
        mp[prefixXor]++;
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(auto &it : v)
        cin >> it;

    int target;
    cin >> target;
    int subarrayCount = solve(v, target);
    cout << "Subarray count = " << subarrayCount << "\n";
    return 0;
}