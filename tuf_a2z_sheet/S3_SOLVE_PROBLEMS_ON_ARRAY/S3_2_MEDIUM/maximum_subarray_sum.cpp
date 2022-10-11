#include <iostream>
#include <vector>
#include <climits>

using namespace std;


int getMaxSum(vector<int> &v)
{
    int currentMax = INT_MIN;
    int overallMax = INT_MIN;

    for(int i = 0; i < v.size(); i++)
    {
        overallMax = max(overallMax + v[i], v[i]);
        currentMax = max(currentMax, overallMax);        
    }
    return currentMax;
}

int main()
{
    cout << "Enter the size of the array\n";
    int n;
    cin >> n;

    vector<int> v(n);

    cout << "Enter the vector elements\n";
    for(auto &it: v)
        cin >> it;

    int maxSum = getMaxSum(v);

    cout << "The maximum subarray sum is = " << maxSum << "\n";

    return 0;
}