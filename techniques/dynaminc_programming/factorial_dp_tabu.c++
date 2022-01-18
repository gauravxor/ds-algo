#include <iostream>
#include <vector>
using namespace std;
int main()
{
    cout << "Enter the number for factorial\n";
    int num;
    cin >> num;

    vector<int> dp;
    dp.resize(num+1);
    
    dp[0] = 1; // base case;

    for(int i=1;i<=num;i++)
    {
        dp[i] = i * dp[i-1];
    }
    cout << "The factorial is = " << dp[num] << "\n";
    return 0;
}