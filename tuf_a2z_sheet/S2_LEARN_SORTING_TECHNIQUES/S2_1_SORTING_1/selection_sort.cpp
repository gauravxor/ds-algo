#include <iostream>
using namespace std;


// TC : O(n^2) | SC : O(1)
void selection_sort(int *arr, int length)
{
	for(int i = 0; i < length - 1; i++)
	{
		int minIndex = i;

		for(int j = i + 1; j < length; j++)
		{
			if(arr[minIndex] > arr[j])
				minIndex = j;
		}

		swap(arr[minIndex], arr[i]);
	}
}

int main()
{
	int length;
	cout << "Enter the size of the array\n";
	cin >> length;

	int arr[length];

	cout << "Enter the array elements\n";
	for(int i = 0; i < length; i++)
		cin >> arr[i];

	selection_sort(arr, length);

	cout << "The array elements after sorting\n";
	for(int val : arr)
		cout << val << " ";
	cout << "\n";

	return 0;
}