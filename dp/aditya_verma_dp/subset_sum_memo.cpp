/**
	Subset Sum Problem.
	Given an array containing some elements and a number N.
	The task is to determine, if sum of any subset of the given array, possibly {}
	result in N.

	Ex: Array = {2,3,1,6,7}
	    N = 11
		O/P -> Possible

	Ex: Array = {2,3,1,5}
		N = 12
		O/P -> Impossible

	This problem is similar to 0/1 Knapsack.
*/

/**
 * For memoization, we need a DP vector, initialized with -1. Initialization is done with -1
 * because that will indicate that the current block is not yet visited.
 */

#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(vector<int>&v, vector<int>&dp, int sum, int n)
{

	if(sum == 0)
		return true;

	if(n == 0)
		return false;

	// checking if the solution of the subproblem already exists.
	if(dp[sum] != -1)
		return dp[sum];

	// if the current value is greater than the sum we want, then we skip the current element
	// and move to the next one. We also make sure to store the answer of the current subproblem
	// in the DP vector.
	if(v[n - 1] > sum)
		return dp[sum] = subsetSum(v, dp, sum, n - 1);
	else
	{
		bool include = subsetSum(v, dp, sum - v[n - 1], n - 1);
		bool exclude = subsetSum(v, dp, sum, n - 1);
		return dp[sum] = (include | exclude);
	}
}

int main()
{
	int n, tsum;
	cout << "Enter the number of elements\n";
	cin >> n;
	vector<int> v(n);

	cout << "Enter the elements of the vector\n";
	for(auto &it: v)
		cin >> it;

	cout << "Enter the target sum\n";
	cin >> tsum;

	vector<int> dp(tsum, -1);
	(subsetSum(v, dp, tsum, n))? cout << "Possible\n" : cout << "Impossible\n";

	return 0;
}