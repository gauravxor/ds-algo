/**
 * In the code present below, we are using a table to precompute
 * the values of smaller subproblems then use the computed values
 * to find the solution of the bigger subproblems.
 * This technique is called tabulation.
 * So we are starting from ground level and moving towards top.
 * This is why we call tabulation as Bottom Up Approach.
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n, vector<int> &dp)
{
    if(n <= 2)
        return dp[n];

    for(int i = 3; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];    
}

int main()
{
    int n;
    cout << "Enter the position for fibonacci\n";
    cin >> n;

    vector<int> dp(n + 1);
    dp[2] = 1;
    int ans = fibonacci(n, dp);

    cout << "Fibinacci = " << ans << "\n";

    return 0;
    
}