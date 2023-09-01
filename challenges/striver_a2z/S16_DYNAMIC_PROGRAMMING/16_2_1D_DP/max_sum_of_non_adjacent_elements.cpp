#include <iostream>
#include <vector>
using namespace std;
/**
 * Naive Recursiv Approach
 * TC : O(2 ^ N) | SC : O(N)
**/
int s1(int index, vector<int> &v) {
    if(index <= 1) {
        return v[0];
    }
    if(index == 1) {
        return max(v[0], v[1]);
    }

    int maxSum = max(s1(index - 2, v) + v[index], s1(index - 1, v));
    return maxSum;
}

/**
 * Recrusion + Memoization
 * TC : O(N) | SC : O(N) + O(N)
**/
int s2(int index, vector<int> &v, vector<int> &dp) {
    if(index == 0) {
        dp[0] = v[0];
        return dp[0];
    }
    if(index == 1) {
        dp[1] = max(v[0], v[1]);
        return dp[1];
    }

    if(dp[index] != 0) {
        return dp[index];
    }

    dp[index] = max(s2(index - 2, v, dp) + v[index], s2(index - 1, v, dp));
    return dp[index];
}

/**
 * Tabulation
 * TC : O(N) | SC : O(N)
**/
int s3(int index, vector<int> &v, vector<int> &dp) {
    dp[0] = v[0];
    if(index > 0) {
        dp[1] = max(v[0], v[1]);
    }
    for(int i = 2; i <= index; i++) {
        dp[i] = max(dp[i - 2] + v[i], dp[i - 1]);
    }
    return dp[index];
}

/**
 * Space Optimized
 * TC : O(N) | SC : O(1)
**/

int s4(int index, vector<int> &v) {
    if(index == 0) {
        return v[0];
    }
    if(index == 1) {
        return max(v[0], v[1]);
    }
    int p1 = v[0], p2 = max(v[0], v[1]);
    int ans = 0;
    for(int i = 2; i <= index; i++) {
        ans = max(p1 + v[i], p2);
        p1 = max(p1, p2);
        p2 = ans;
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
    int maxSum;
    // maxSum = s1(n - 1, v);
    vector<int> dp(n, 0);
    // maxSum = s2(n - 1, v, dp);
    // maxSum = s3(n - 1, v, dp);
    maxSum = s4(n - 1, v);
    cout << maxSum << "\n";
    return 0;
}