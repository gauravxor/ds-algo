#include <iostream>
#include <vector>
using namespace std;

// in tabulation, we take the number of items as rows and maximum weight of the
// knapsack as column data. When the weight of knapsack is 0, we cannot fit any
// items in it so the profit made at the condition is 0 and when there is no item
// to put in the knapsack, the profit made in that case will be zero as well,
// hence we initialize the first row and first column with 0.

// the weight and profit vectors follow 0 based indexing, and the first row/col
// is already occupied with 0, we always subtract 1 from the current index, when
// we want the value of weight/profit at a given index.

// since the capacity is taken in column, if the capacity is 10, then the number
// of columns to be generated is also 10.
int getMaxVal(vector<int>&weight, vector<int>&profit, int cap, int items)
{
    vector<vector<int>> dp(items + 1, vector<int>(cap + 1, 0));

    // loop for items, that represents the rows.
    for(int i = 1; i <= items; i++)
    {
        // loop for the weights, that represents the columns.
        for(int wt = 1; wt <= cap; wt++)
        {
            // if the weight of the item at the current index is greater than the capacity
            // of the knapsack at the current index, then we take the previous row's value
            // in the current row as well.
            if(weight[i - 1] > wt)
                dp[i][wt] = dp[i - 1][wt];
            else
            {
                // If the weight of the item at the current index is okay to take, then we have two
                // options, either take it or leave it.
                // If we are taking the item, then make sure to include the profit given by the current
                // item and the MAXIMUM profit that is made when the weight of the current item is included.
                // By included we mean, reducing it from the current weight.

                // If we are exluding the item, then we dont have to worry about the profit made by the
                // current item. We just take the profit made by the previous item(which is the max profit)
                // if we dont include the current item.
                int include = profit[i - 1] + dp[i - 1][wt - weight[i - 1]];
                int exclude = dp[i - 1][wt];

                // then just take the maximum of those two values and store it in the current DP cell.
                dp[i][wt] = max(include, exclude);
            }
        }
    }

    return dp[items][cap];

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

	int maxVal = getMaxVal(weight, values, w, items);
	cout << "The maximum weight that can be taken is = " << maxVal << "\n";
	return 0;
}