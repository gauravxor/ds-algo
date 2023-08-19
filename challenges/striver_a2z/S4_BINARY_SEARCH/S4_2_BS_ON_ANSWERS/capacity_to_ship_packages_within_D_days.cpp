#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;


int getTime(vector<int> &v, int capacity) {
    int timeTaken = 1;
    int weightLoaded = 0;

    for(int i : v) {
        if(weightLoaded + i <= capacity) {
            weightLoaded += i;
        }
        else {
            timeTaken++;
            weightLoaded = i;
        }
    }
    return timeTaken;
}


int solve(vector<int> &v, int target) {
    int low = *max_element(v.begin(), v.end());
    int high = accumulate(v.begin(), v.end(), 0);

    int ans = high;

    while(low <= high) {
        int mid = (low + high) / 2;
        int timeTaken = getTime(v, mid);

        // more time is taken, indicating that current capactiy should be increased
        if(timeTaken > target) {
            low = mid + 1;
        }
        else {
            //time taken is fine, so push and check how low we can go
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
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

    int ans = solve(v, target);
    cout << ans << "\n";
    return 0;
}