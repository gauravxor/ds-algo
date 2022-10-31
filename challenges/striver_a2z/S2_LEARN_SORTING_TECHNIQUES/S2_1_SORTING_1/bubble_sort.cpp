#include <iostream>
using namespace std;

// TC : O(n^2) | SC : O(1)

void bubble_sort(int *arr, int length)
{
	for(int i = 0; i < length - 1; i++)
	{
		for(int j = 0; j < length - i - 1; j++)
		{
			if(arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
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

	bubble_sort(arr, length);

	cout << "The array elements after sorting\n";
	for(int val : arr)
		cout << val << " ";
	cout << "\n";

	return 0;
}