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
*/

/**
 *  For tabulation, we need a 2D vector, where the needed sum is considered as column,
 * 	and the number of elements is treated as rows.
 *
 * 	Initialization is done by keeping two things in mind
 *  i) If the given array is empty then it's impossible to reach any solution. In this is case,
 *  we can reach to solution only if SUM = 0.
 *  SO THE FIRST ROW OF DDA IS MARKED AS 0 (FALSE). ONLY THE CELL (0, 0) IS TRUE.
 *
 *	ii) If the solution we want is 0, i.e. SUM = 0, then this solution is reachable in every way, doesnot
 *	matter what is the size of the given array.
 *	SO THE FIRST COLUMN IF DDA IS MARKED 1 (TRUE).
 */

#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(vector<int>&v, int sum, int n)
{
	// generating a 2D vector of size (n + 1, sum + 1)
	vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

	// initializing the first column to TRUE.
	for(int i = 0; i <= n; i++)
		dp[i][0] = 1;

	// initializing the first row to FALSE.(except (0, 0))
	for(int i = 1; i <= sum; i++)
		dp[0][i] = 0;


	// loop for the number of elements in array
	for(int id = 1; id <= n; id++)
	{
		// loop for the needed sum.
		for(int s = 1; s <= sum; s++)
		{
			// if the current element's value is greater than the SUM of the SUBPROBLEM
			// we are processing, we have nothing to process and we take the previous
			// computed value.
			if(v[id - 1] > s)
				dp[id][s] = dp[id - 1][s];
			else
			{
				// if the current element's value is <= SUM of the SUBPROBLEM we are processing,
				// we again have two choices, either we take it or leave it.

				// when we are including the current element, we need to take the solution of the
				// previous subproblem, SUCH THAT, "SUM" OF THAT SUBPROBLEM AND THE CURRENT PROBLEM
				// DOESNOT EXCEEDS THE REQUIRED VALUE OF SUM(I/P).
				int include = dp[id - 1][s - v[id - 1]];

				// if we are not including the current element, we just take the solution of previous
				// subproblem (which gives the maximum/best value possible till then).
				int exclude = dp[id - 1][s];


				dp[id][s] = (include | exclude);
			}
		}
	}
	return dp[n][sum];
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

	(subsetSum(v, tsum, n))? cout << "Possible\n" : cout << "Impossible\n";
	return 0;
}