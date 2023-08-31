#include <climits>
#include <iostream>
#include <vector>
using namespace std;

/**
 * Naive recursive approach
 * TC : O(K ^ N)  | SC : O(N)
**/
int s1(int index, int k, vector<int> &v) {
    if (index <= 0) {
        return 0;
    }
    int cost = INT_MAX;
    for (int i = 1; i <= k; i++) {
        if (index - i >= 0) {
            int step = s1(index - 1, k, v) + abs(v[index] - v[index - i]);
            cost = min(cost, step);
        }
    }
    return cost;
}

/**
 * Recursive approach + Memoization
 * TC : O(N * K)  |  SC : O(N) + O(N)
**/
int s2(int index, int k, vector<int> &heights, vector<int> &dp) {
    if (index <= 0) {
        return 0;
    }
    if (dp[index] != 0) {
        return dp[index];
    }

    int minCost = INT_MAX;
    for (int i = 1; i <= k; i++) {
        if (index - i >= 0) {
            int cost = s2(index - 1, k, heights, dp) + abs(heights[index] - heights[index - i]);
            minCost = min(minCost, cost);
        }
    }
    dp[index] = minCost;
    return dp[index];
}

/**
 * Tabulation
 * TC : O(N * K)  |  SC : O(N)
**/
int s3(int index, int k, vector<int> &heights, vector<int> &dp) {
    for (int i = 1; i <= index; i++) {
        int cost = INT_MAX;
        for(int j = 1; j <= k; j++) {
            if(i - j >= 0) {
                cost = min(cost, dp[i - j] + abs(heights[i] - heights[i - j]));
            }
        }
        dp[i] = cost;
    }
    return dp[index];
}


/**
 * Space Optimized
 * TC : O(N * K)  |  SC : O(K)
**/
int s4(int index, int k, vector<int> &heights) {
    vector<int> dp(k);

    for(int i = 1; i <= index; i++) {
        int cost = INT_MAX;

        for(int j = 1; j <= k; j++) {
            if(i - j >= 0) {
                cost = min(cost, dp[k - j] + abs(heights[i] - heights[i - j]));
            }
        }
        for(int j = 0; j < k - 1; j++) {
            dp[j] = dp[j + 1];
        }
        dp[k - 1] = cost;
    }
    return dp[k - 1];
}


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    int minCost;
    // vector<int> dp(n);
    // minCost = s1(n - 1, k, heights);
    // minCost = s2(n - 1, k, heights, dp);
    // minCost = s3(n - 1, k, heights, dp);
    minCost = s4(n - 1, k, heights);
    cout << minCost << "\n";
    return 0;
}