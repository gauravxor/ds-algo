/**
 * Equal Sum Partition
 *
 * Given an array containing some elements. We have check if there exists any partition
 * such that the sum of all the elements of both the partition is same.
 */


/**
 * The logic behind the problem is straightforward.
 * We first need to find the sum of the all the elements of the given array.
 *
 * If the sum is odd, that means it's impossible to divide the array in two
 * parts such that their sums are equal.
 *
 * If the sum is even, then we MIGHT say that the solution is possible. We cannot
 * guanrantee as if array is [3, 5], then even if the sum is even(8), we cannot
 * partiton the array equally.
 * So if the sum is an equal number, we just need to find IF THERE EXISTS ANY SUBSET
 * SUCH THAT IT'S SUM IS HALF OF THE SUM OF THE GIVEN VECTOR.
 * If we are able to find such subset, that means there will be another subset where
 * the sum will be the exact value.
 *
 * HENCE THE PROBLEM IS REDUCED TO SUBSET SUM PROBLEM!
 */

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool subsetSum(vector<int>&v, int sum, int n)
{
	vector<vector<int>> dp(n + 1, vector<int>(sum + 1));

	for(int i = 0; i <= sum; i++)
		dp[0][i] = false;

	for(int i = 0; i <= n; i++)
		dp[i][0] = true;

	for(int i = 1; i <= n; i++)
	{
		for(int s = 0; s <= sum; s++)
		{
			if(v[i - 1] > s)
				dp[i][s] = dp[i - 1][s];
			else
			{
				int include = dp[i - 1][s - v[i - 1]];
				int exclude = dp[i - 1][s];
				dp[i][s] = (include | exclude);
			}
		}
	}
	return dp[n][sum];
}

bool sumParition(vector<int>&v)
{
	int sum = accumulate(v.begin(), v.end(), 0);
	if(v.size() == 0 || (sum & 1) == 1)
		return false;
	return subsetSum(v, sum / 2, v.size());

}

int main()
{
	int n;
	cout << "Enter the number of elements in the array\n";
	cin >> n;

	vector<int> v(n);
	cout << "Enter the vector elements\n";

	for(auto &it: v)
		cin >> it;

	(sumParition(v))? cout << "Possible\n" : cout << "Not Possible\n";
	return 0;

}