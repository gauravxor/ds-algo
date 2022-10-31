/**
 * Merge Overlapping Invervals
 *-----------------------------
 * 
 * Given a list of intervals and we have to merge the
 * overlapping intervals together.
 * 
 * Input : {2, 5}, {1, 4}
 * Output : {1, 5}
 * 
 * Algorithm:
 * -----------
 * 
 * Sort the intervals in the increasing order of their 
 * starting position. Now store the first interval in a vector(ans) and
 * check if the next interval(sorted) is overlapping. If the next interval is
 * overlapping then modify the previous interval accordingly or else insert 
 * the current interval in the answer vector.
 * Keep repeating the steps and return the merged intervals.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
	int length = intervals.size();
	vector<vector<int>> ans;

	sort(intervals.begin(), intervals.end());

	ans.push_back(intervals[0]);
	int index = 0;

	for(int i = 1; i < length; i++)
	{
		if(ans[index][1] >= intervals[i][0])
		{
			ans[index][0] = min(ans[index][0], intervals[i][0]);
			ans[index][1] = max(ans[index][1], intervals[i][1]);
		}
		else
		{
			index++;
			ans.push_back(intervals[i]);
		}
	}

	return ans;

}
int main()
{
	int size;
	cout << "Enter the number of intervals\n";
	cin >> size;

	vector<vector<int>> intervals(size,{0,0});
	
	cout << "Enter the intervals\n";
	for(int i = 0; i < size; i++)
	{
		cout << "Enter the start and end\n";
		cin >> intervals[i][0] >> intervals[i][1];
	}

	vector<vector<int>> merged = mergeIntervals(intervals);

	cout << "The merged intervals are\n";
	for(int i = 0; i < merged.size(); i++)
		cout << merged[i][0] << " " << merged[i][1] << "\n";
	return 0;

}