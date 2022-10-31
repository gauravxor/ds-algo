#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[], int left, int right)
{
	int leftIndex = left;
	int rightIndex = right;
	int pivot = arr[left];

	while(leftIndex < rightIndex)
	{
		while(leftIndex < right && arr[leftIndex] <= pivot)
			leftIndex++;

		while(rightIndex >= left && arr[rightIndex] > pivot)
			rightIndex--;

		if(leftIndex < rightIndex)
			swap(arr[leftIndex], arr[rightIndex]);
	}
	swap(arr[left], arr[rightIndex]);
	return rightIndex;
}

void quick_sort(int *arr, int left, int right)
{
	if(left < right)
	{
		int pivotPosition = partition(arr, left, right);
		quick_sort(arr, left, pivotPosition - 1);
		quick_sort(arr, pivotPosition + 1, right);
	}
}

int main()
{
	cout << "Enter the size of the array\n";
	int length;
	cin >> length;

	int arr[length];

	cout << "Enter the array elements\n";
	for(int  i = 0; i < length; i++)
		cin >> arr[i];

	cout << "partition = " << partition(arr, 0, length - 1) << "\n";
	quick_sort(arr, 0, length - 1);

	cout << "The sorted array is\n";
	for(int i = 0; i < length; i++)
		cout << arr[i] << " ";

	cout << "\n";
	return 0;

}