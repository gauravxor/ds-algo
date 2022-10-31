#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> v)
{
	int low = 0;
	int high = v.size() - 1;

	while(low <= high)
	{
		int mid = (low + high) / 2;
		if((mid == 0 || v[mid - 1] == 0) && v[mid] == 1)
			return mid;

		if(v[mid] == 0)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return high + 1;

}

int largest_row(vector<vector<int>> &v)
{
	int rows = v.size();
	int cols = v[0].size();
	int ans = -1;
	int maxOneCount = 0;
	for(int i = 0; i < rows; i++)
	{
		int firstIndex = search(v[i]);
		if(firstIndex != cols)
		{
			if(cols - firstIndex > maxOneCount)
			{
				maxOneCount = cols - firstIndex;
				ans = i;
			}
		}
	}
	return ans;
}

int main()
{
	int rows, cols;
	cout << "Enter the number of rows\n";
	cin >> rows;

	cout << "Enter the number of columns\n";
	cin >> cols;

	vector<vector<int>> v(rows, vector<int>(cols));

	cout << "Enter the elements in matrix\n";
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
			cin >> v[i][j];
	}



	int ans = largest_row(v);
	if(ans == -1)
		cout << "Matrix does not contains 1 in any index\n";
	else
		cout << "Maximum number of 1s were found at " << ans << "\n";
	return 0;
}