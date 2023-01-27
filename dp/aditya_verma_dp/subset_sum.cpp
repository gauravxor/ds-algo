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

#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(vector<int>&v, int sum, int n)
{

	// if the required sum is 0, we have reached the solution.
	if(sum == 0)
		return true;

	//if the array is empty, then it is impossible to generate sum of any value.
	if(n == 0)
		return false;

	// if the current elements is greater than the needed sum, we cannot include it.
	// so we move to the next element and check if it is good to go.
	if(v[n - 1] > sum)
		return subsetSum(v, sum, n - 1);
	else
	{
		// if the current element is smaller than the needed sum, we may or maynot include
		// in the subset. So here we have two choices, just like 0/1 Knapsack Problem

		// if we are considering the current element, then for further calculation the value
		// of sum will get reduced by the current element's value.
		bool include = subsetSum(v, sum - v[n - 1], n - 1);

		// if we are not considering the current element, then for further calculation, we
		// can just move on to the next element.
		bool exclude = subsetSum(v, sum, n - 1);

		// if either two of above operation brings the value TRUE, then we will consider it.
		return (include | exclude);
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

	(subsetSum(v, tsum, n))? cout << "Possible\n" : cout << "Impossible\n";

	return 0;
}