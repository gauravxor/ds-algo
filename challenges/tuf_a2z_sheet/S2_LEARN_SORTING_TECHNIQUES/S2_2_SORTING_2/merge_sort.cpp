#include <iostream>
using namespace std;


void merge(int *arr, int left, int mid, int right)
{

	int leftLength = mid - left + 1;
	int rightLength = right - mid;

	int leftSegment[leftLength];
	for(int i = left; i <= mid; i++)
		leftSegment[i - left] = arr[i];

	int rightSegment[rightLength];
	for(int i = mid + 1; i <= right; i++)
		rightSegment[i - mid - 1] = arr[i];


	int leftIndex = 0;
	int rightIndex = 0;
	int mainIndex = left;

	while(leftIndex < leftLength && rightIndex < rightLength)
	{
		if(leftSegment[leftIndex] <= rightSegment[rightIndex])
			arr[mainIndex++] = leftSegment[leftIndex++];
		else
			arr[mainIndex++] = rightSegment[rightIndex++];
	}
	
	while(leftIndex < leftLength)
		arr[mainIndex++] = leftSegment[leftIndex++];

	while(rightIndex < rightLength)
		arr[mainIndex++] = rightSegment[rightIndex++];
}


void merge_sort(int *arr, int left, int right)
{
	// if there are more than 1 elements in the array
	if(left < right)
	{
		int mid = (right + left) / 2;

		// calling the merge sort for the leftmost portion
		merge_sort(arr, left, mid);

		// calling the merge sort for the rightmost portion
		merge_sort(arr, mid + 1, right);

		// merging both the left and right segments

		merge(arr, left, mid, right);
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

	merge_sort(arr, 0, length - 1);


	cout << "The sorted array is\n";
	for(int i = 0; i < length; i++)
		cout << arr[i] << " ";

	cout << "\n";
	return 0;

}