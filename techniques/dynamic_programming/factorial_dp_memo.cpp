#include <iostream>
#include <vector>
using namespace std;

// memoized dp
int f(int num, vector<int> &dp)
{
    if(num <= 0)
        return 1;
    dp[num] = num * f(num - 1,dp);
    return dp[num];
}

int main()
{
    cout << "Enter the number\n";
    int num;
    cin >> num;

    vector<int> dp(num+1,0);
    dp[0] = 1; // base case

    int fact = f(num,dp);
    cout << "The factorial is = " << fact << "\n";
    return 0;    
}