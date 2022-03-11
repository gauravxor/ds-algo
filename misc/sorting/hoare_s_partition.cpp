/**
 * Implementation of Hoare's Partition Scheme
 * 
 * This technique nakes practically less number of comaparisons
 * than the comparison made by Lomuto Partitioning technique.
 * 
 * 
 * Assumptions : 
 * The first element is the pivot. If we want something else
 * then we can swap it with the first element to get our 
 * job done.
 * 
 * 
 * Algorithm :
 * -----------
 * 
 * 
 * Keep two pointers, one at the beginning and one at the end.
 * Increment the first pointer (one at the beginning) till an 
 * element that is greater than pivot is encountered.
 * 
 * Similarly keep decrementing the second pointer (one at the end)
 * till an element that is smaller than pivot is encountered.
 * 
 * If the first pointer reaches the second pointer then the 
 * partitioning is done and return position of pivot element or
 * else, swap the elements at the left and right pointer.
 * 
 * When we are swapping the two elements we are technically moving the
 * smaller element at the beginning of the array and larger one at the
 * end.
 * 
 * NOTE : Hoare's partition algorithm doesnot ensures that the pivot is
 * placed at it's correct positio but lomuto partitioning does. This algorithm
 * returns the correct position of the pivot. We may perform changes accordingly
 * to bring pivot to its final position.
 * 
 **/

#include <iostream>
using namespace std;

int partition(int * arr, int low, int high)
{
	int pivot = arr[low];  // considering the first element as pivot
	int left = low - 1;
	int right = high + 1;
	while(true)
	{
		do
		{
			left++;
		}
		while(arr[left] < pivot);
		
		do
		{
			right--;
		}
		while(arr[right] > pivot);
		
		if(left >= right)
			return right;
		swap(arr[left], arr[right]);
	}
}

int main()
{
	int size;
	cout << "Enter the size of the array\n";
	cin >> size;

	int arr[size];

	for(int i = 0; i < size; i++)
		cin >> arr[i];


	cout << "The original array\n";
	for(int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";


	int pos;
	cout << "Enter the pivot position\n";
	cin >> pos;
	pos--;
	
	// Moving selected pivot to the beginning.
	swap(arr[0], arr[pos]);

	int pp = 1 + partition(arr, 0, size - 1);

	cout << "Pivot position after partitioning  = " << pp << "\n";
	
	cout << "The partitioned array is\n";
	for(int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";
	return 0;
}