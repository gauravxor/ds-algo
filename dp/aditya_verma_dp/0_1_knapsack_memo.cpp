/**
 * Given weights and values of N items, put these items in a knapsack of
 * capacity W to get the maximum total value in the knapsack possible.
 * The value of each item is reperesented by a value array V.
 */

#include <iostream>
#include <vector>
using namespace std;

// to compare the difference between number of recursive calls made, when
// using normal recursion and recursion without memoization.
int calls = 0;

// DDA of size 100 x 100, preinitialized with -1
// IMPORTANT -> We take the capacity of Knapsack as Column and number
// of items as rows.
vector<vector<int>> dp(100, vector<int>(100, -1));

int getMaxValue(int id, int cap, vector<int> &wt, vector<int> &val)
{
    calls++;
    if(id == 0 || cap == 0)
        return 0;

    // checking if the subproblem that we are trying to solve has been
    // solved already or not. If it is, then we will take that value or else
    // try to solve the subproblem.
    if(dp[id][cap] != -1)
        return dp[id][cap];

    // solving the subproblem
    // if the weight of current item is > capacity of the kanpsack, we will
    // just ignore that item and move to the next one.
    if(wt[id - 1] > cap)
        return getMaxValue(id - 1, cap, wt, val);
    else
    {
        // if the current weight of the item is suitable, then we have two choices,
        // either we take it or leave it and the answer will be the maximum of
        // th result producted by both of the choices.
        int incl = val[id - 1] + getMaxValue(id - 1, cap - wt[id - 1], wt, val);
        int excl = getMaxValue(id - 1, cap, wt, val);

        // after calcualtion is done, we need to make sure that the DDA has the answer
        // for the subproblem that we are currenly trying to solve for further use.
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

    cout << "\n";
    return 0;
}