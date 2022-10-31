/**
 * Implementation of Merge Sort 
 * 
 * It is a divide and conquer algorithm
 * where we divide the array into smaller partitions
 * and then sort then individually and finally merge them.
 * 
 * The dividing of array is done, IFF THERE IS MORE THAN 1
 * ELEMENTS TO DIVIDE.
 * 
 * 
 * Technique :
 * TC_BC : O(n logn)
 * TC_WC : O(n ^ 2)
 * SC    : O(log n)  // auxillary stack space for recursive calls.
 * -------------------------------------------
 * 
 * 1) Take an array, find it's middle element using
 *    (low + high) / 2. Keep on partitioning the array
 *	  till there is less than 2 elements left in the range.
 * 	  (this is the quick sort function)
 * 
 * 
 * 2) Store somewhere the left part of the array (before mid)
 *    and right part of the array (ater mid). And merge them.
 * 	  (this is the merge function)
 * 
 * 3) Keep doing this and at the end we will have to sorted array.
 * */


#include <iostream>
using namespace std;

void merge(int * arr, int low, int mid, int high)
{
	int leftSize = mid - low + 1;
	int rightSize = high - mid;
		
	int left[leftSize];
	int right[rightSize];

	int curr = 0;
	for(int i = low; i <= mid ; i++)
		left[curr++] = arr[i];

	curr = 0;
	for(int i = mid + 1 ; i <= high; i++)
		right[curr++] = arr[i];

	int i = 0;
	int j = 0;
	curr = low;
	while(i < leftSize && j < rightSize)
	{
		if(left[i] <= right[j])
			arr[curr++] = left[i++];
		else
			arr[curr++] = right[j++];
	}

	while(i < leftSize)
		arr[curr++] = left[i++];
	while(j < rightSize)
		arr[curr++] = right[j++];
}

void mergeSort(int * arr, int low, int high)
{
	if(low < high)  // if there is more than one element
	{
		int mid = low + (high - low) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}


int main()
{
	int size;
	cout << "Enter the size of the array\n";
	cin >> size;

	cout << "Enter the array elements\n";
	int arr[size];

	for(int i = 0; i < size; i++)
		cin >> arr[i];


	cout << "Original array\n";
	for(int i = 0 ; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";

	mergeSort(arr, 0, size - 1);


	cout << "Sorted array\n";
	for(int i = 0 ; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";

	return 0;
}