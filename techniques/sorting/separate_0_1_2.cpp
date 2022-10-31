/**
 * Given an array containing 0, 1 and 2.
 * The task is to separate all the elements in their
 * individual groups.
 * 
 * Input : [1,2,0,0,1,1,0,2,0]
 * Output: [0,0,0,1,1,1,1,2,2]
 * 
 * 
 * 
 * Algorithm (Dutch National Flag Algorithm)
 * TC : O(n) | SC : O(1)
 * ------------------------------------------
 *
 * Dutch National Flag Algorithm is a variation of
 * Hoare's Parititon Algorithm.
 * 
 * The Simple Idea of the aglorithm is, while 
 * traversing the array from top :
 * 
 * 1] If we get 0, then swap it with the first index(low),
 * increment the first index and move on.
 * 2] If we get 1, then we dont have to do anything and
 * move forward.
 * 3] If we get two, then swap it with the last index(high)
 * and decrement the last index and move on
 * 
 * 
 **/
 
#include <iostream>
using namespace std;

void dnf(int *arr, int size)
{
	int low = 0, mid = 0, high = size;
	while(mid <= high)
	{
		if(arr[mid] == 0)
			swap(arr[low++], arr[mid++]);
		else
		if(arr[mid] == 1)
			mid++;
		else
		{
			swap(arr[mid], arr[high]);
			high--;
		}
	}
}

int main()
{
	int size;
	cout << "Enter the number of array elements\n";
	cin >> size;

	int arr[size];

	cout << "Enter the array elements\n";
	for(int i = 0; i < size; i++)
		cin >> arr[i];

	cout << "The array before grouping\n";
	for(int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";

	dnf(arr, size - 1);

	cout << "The array after grouping\n";
	for(int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";

	return 0;
}