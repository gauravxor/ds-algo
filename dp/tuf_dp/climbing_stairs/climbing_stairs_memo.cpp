/**
 * Memoized approach of Climbing stairs problem
 * 
 * TC : O(n) | SC : O(n) (Techincally 2n, for DP vector and stack space)
 */

#include <iostream>
#include <vector>
using namespace std;

int calls = 0;


int countSteps(int n, vector<int> &dp)
{
    if(n <= 2)
        return dp[n];
    
    if(dp[n] != 0)
        return dp[n];
    
    int oneStep = countSteps(n - 1, dp);
    int twoStep = countSteps(n - 2, dp);
    
    dp[n] = oneStep + twoStep;
    
    return dp[n];
}


int main()
{
    cout << "Enter the number of stairs\n";
    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);
    dp[1] = 1; // predefined value
    dp[2] = 2; // predefined value

    int ans = countSteps(n, dp);
    cout << "The no. of unique steps is = " << ans << "\n";
    cout << "Total recursive calls = " << calls << "\n";
    return 0;
}