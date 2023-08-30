#include <iostream>
#include <vector>
using namespace std;

/** Recursive Code without memoization */
int getNthFib(int n) {
    if(n <= 2) {
        return 1;
    }
    return getNthFib(n - 1) + getNthFib(n - 2);
}

/** Recursive Code with memoization */
int getNthFib(int n, vector<int> &dp) {
    if (n <= 2) {
        return dp[n];
    }
    if(dp[n] != 1) {
        return dp[n];
    }
    int left = getNthFib(n - 1, dp);
    int previousLeft = getNthFib(n - 2, dp);

    dp[n] = left + previousLeft;
    return dp[n];
}


/** Iterative Code Tabulation */
int getNthFibTab(int n) {
    vector<int> dp(n + 1, 1);

    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

/** Iterative code but space optimized */
int getNthFibOpt(int n) {
    if(n <= 2) {
        return 1;
    }
    int l = 1, ll = 1, ans = 0;
    for(int i = 3; i <= n; i++) {
        ans = l + ll;
        ll = l;
        l = ans;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    // vector<int> dp(n + 1, 1);

    int nthFib = getNthFibOpt(n);
    cout << nthFib << "\n";
    return 0;
}