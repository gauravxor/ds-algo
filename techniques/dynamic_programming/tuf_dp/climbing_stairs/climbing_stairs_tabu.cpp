/**
 * Tabulated approach of Climbing stairs problem
 * 
 * TC : O(n) | SC : O(n) (For DP vector)
 */

#include <iostream>
#include <vector>
using namespace std;

int countSteps(int n)
{
    if(n <= 2) return n;

    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}


int main()
{
    cout << "Enter the number of stairs\n";
    int n;
    cin >> n;

    int ans = countSteps(n);
    cout << "The no. of unique steps is = " << ans << "\n";
    return 0;
}