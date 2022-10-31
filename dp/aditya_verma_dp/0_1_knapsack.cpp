/**
 * Given weights and values of N items, put these items in a knapsack of 
 * capacity W to get the maximum total value in the knapsack possible.
 * The value of each item is reperesented by a value array V.
 */

#include <iostream>
#include <vector>
using namespace std;

int calls = 0;
int getMaxValue(int id, int cap, vector<int> &wt, vector<int> &val)
{
    calls++;
    // base case, i.e. if the there are no items available (or we have reached
    // the end of the items list due to reursive calls) or the capacity of the
    // knapsack has become zero or it was zero right from the beginning.
    if(id == 0 ||  cap == 0)
        return 0;
    

    // if the current weight we are about to select, exceeds the available
    // capacity of the knapsack, then we will skip the current item.
    if(wt[id - 1] > cap)
        return getMaxValue(id - 1, cap, wt, val);
    else
    {
        // if the weight of the current item is considerable, then we have two
        // option i.e. either we take that item or move to the next item.
        
        // we are including the item
        int incl = val[id - 1] + getMaxValue(id - 1, cap - wt[id - 1], wt, val);

        // we are exluding the item
        int excl = getMaxValue(id - 1, cap, wt, val);

        return max(incl, excl);
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
    return 0;
} 