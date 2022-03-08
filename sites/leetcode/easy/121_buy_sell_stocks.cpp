/**
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * 
 * 
 * Follow up:
 * -----------
 * If the price vector has some negative values as well 
 * then we may use the "Kadane's Algorithm" to find the
 * maximum sum subarray and return the answer.
 * 
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    
        int profit = 0, minPrice = prices[0];
        int size = prices.size();
        for(int i=1; i<size; i++)
        {
            minPrice = min(prices[i], minPrice);
            profit = max(profit, prices[i] - minPrice);
        }
        return profit;
    }
};

int main()
{
    Solution sol;
    vector<int> prices{1,2,4,5,6};
    cout << sol.maxProfit(prices) << "\n";
    return 0;
}