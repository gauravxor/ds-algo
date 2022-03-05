/** 
 * Implementation of Lomuto Partitioning Scheme
 * 
 * Assumptions : The last element is the pivot.
 * If we want another element to be the pivot,
 * then we swap that element with the last one
 * and use the same algorithm.
 * 
 * 
 * Algorithm
 * -----------
 * 
 * Initialize a pointer position with the starting
 * point of the array and start traversing the array
 * from the beginning.
 * 
 * If current element is smaller than the pivot element
 * then swap the "starting pointer" with the current 
 * element and increase the "starting pointer".
 * 
 * If some element is greater than the pivot element then
 * the "starting pointer" will remain at its place waiting for
 * a smaller element to appear.
 * 
 * Keep doing this and we will get the paritioned array.
 **/

#include <iostream>
#include <algorithm>
using namespace std;

int partition(int * arr, int low, int high)
{
	int pos = low - 1;
	int pivot = arr[high];
	for(int i = low; i <= (high - 1); i++)
	{
		if(arr[i] < pivot)
		{
			pos++;
			swap(arr[pos], arr[i]);
		}
	}
	swap(arr[++pos], arr[high]);
	return pos;
}

int main()
{
	int size;
	cout << "Enter the size of the array\n";
	cin >> size;

	int arr[size];

	for(int i = 0; i < size; i++)
		cin >> arr[i];

	int pos;
	cout << "Enter the pivot position\n";
	cin >> pos;

	pos--;


	cout << "The original array is\n";
	for(int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";

	// Swapping the selected pivot with the last element
	swap(arr[pos],arr[size - 1]);

	int pp = partition(arr, 0, size - 1);
	cout << "Pivot position after partition = " << pp << "\n";

	cout << "The partitioned array is\n";
	for(int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";

	return 0;
}