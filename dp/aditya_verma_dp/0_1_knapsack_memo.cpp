/**
 * Given weights and values of N items, put these items in a knapsack of 
 * capacity W to get the maximum total value in the knapsack possible.
 * The value of each item is reperesented by a value array V.
 */

#include <iostream>
#include <vector>
using namespace std;

int calls = 0;
vector<vector<int>> dp(100, vector<int>(100, -1));

int getMaxValue(int id, int cap, vector<int> &wt, vector<int> &val)
{
    calls++;
    if(id == 0 || cap == 0)
        return 0;
    
    if(dp[id][cap] != -1)
        return dp[id][cap];
    
    if(wt[id - 1] > cap)
        return getMaxValue(id - 1, cap, wt, val);
    else 
    {
        int incl = val[id - 1] + getMaxValue(id - 1, cap - wt[id - 1], wt, val);
        int excl = getMaxValue(id - 1, cap, wt, val);
        dp[id][cap] = max(incl, excl);
        return dp[id][cap];
    }
}

int main()
{
    cout << "Enter the numnber of items\n";
    int items;
    cin >> items;

    vector<int> weight(items);
    vector<int> values(items);

    cout << "Enter the weight vector\n";
    for(int i = 0; i < items; i++)
        cin >> weight[i];

    cout << "Enter the value vector\n";
    for(int i = 0; i < items; i++)
        cin >> values[i];

    cout << "Enter the total capacity of the Knapsack\n";
    int w;
    cin >> w;
    int ans = getMaxValue(items, w, weight, values);
    cout << "The maximum that can be obtained = " << ans << "\n";
    cout << "Total recursive calls = " << calls << "\n";


    cout << "\nThe dp vector is\n";

    for(int i = 0; i <= items; i++)
    {
        for(int j = 0; j <= w; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
    return 0;
} 