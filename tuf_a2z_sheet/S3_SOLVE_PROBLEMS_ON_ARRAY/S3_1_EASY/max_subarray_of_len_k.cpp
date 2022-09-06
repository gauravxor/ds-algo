#include <iostream>
#include <unordered_map>
using namespace std;

int get_max_len(int *arr, int length, int target)
{
	unordered_map<int, int> umap;

	int sum = 0;
	int maxLength = 0;

	for(int i = 0; i < length; i++)
	{
		sum += arr[i];
		
		// if this condition becomes true, then we know that
		// current element is the longeste subarray resulting
		// target sum
		if(sum == target)
			maxLength = i + 1;


		if(umap.find(sum) == umap.end())
			umap[sum] = i;

		if(umap.find(sum - target) != umap.end())
			maxLength = max(maxLength, i - umap[sum - target]);
	}

	return maxLength;
}

int main()
{
	int len;
	cout << "Enter the size of array\n";
	cin >> len;

	int arr[len];

	cout << "Enter the array elements\n";
	for(int i = 0; i < len; i++)
		cin >> arr[i];

	int target;
	cout << "Enter the target\n";
	cin >> target;

	cout << "The subarray with max length is ";
	int maxLen = get_max_len(arr, len, target);
	cout << maxLen << "\n";

	return 0;
}