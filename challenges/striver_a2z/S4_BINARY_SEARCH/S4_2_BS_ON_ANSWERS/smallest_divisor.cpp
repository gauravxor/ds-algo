#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int getSum(vector<int> &v, int d) {
    int sum = 0;
    for(int i : v) {
        double result = (double)i / (double)d;
        sum += ceil(result);
    }
    return sum;
}


int solve(vector<int> &v, int target) {
    int low = 1;
    int high = *max_element(v.begin(), v.end());

    int ans = 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        int sum = getSum(v, mid);

        // high sums, because divisors are small, resulting in larger quotients
        if(sum > target) {
            low = mid + 1;
        }
        else {
            // we got the answer,but push to see how low we can go
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}


int main () {
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