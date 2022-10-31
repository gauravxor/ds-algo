/**
 *  IMPLEMENTATION OF NATIVE APPROACH TO PARITION AN ARRAY
 * 
 *  Given an array containing N elements.
 *  We need to partition the array around a given element
 * 	within the specified range.
 * 
 * If the array is [5,6,2,1,4,9,7] and the paritioning 
 * element is 4, then we have to arrange the elements
 * of the array in such a way that all the elements before the
 * paritition element is smaller than or equal and all the
 * elements to the right is greater than or equal to the 
 * parition element. The paritioned elements can be in any order
 * 
 * So the resulting array will be [1,2,4,5,6,7,9]
 * 
 * FOR PARTITIONING, WE WILL ALSO BE GIVEN THE RANGE.
 * 
 * THE TECHNIQUE FAILS WHEN THERE ARE SMALLER ELEMENTS PRESENT
 * AFTER THE PARTITON POINT, AS DURING THE FIRST TRAVERSAL THE
 * LARGER ELEMENTS WILL BE INSERTED BEFORE THE SMALLER ONES.
 * IF [6, 3, 1, 2, 4, 9] AND THE PARTITION POINT IS 9 OR 6, THE
 * ALGORITHM FAILS.
 * 
 **/


#include <iostream>
using namespace std;


void partition(int * arr, int low, int high, int part)
{
	int temp[high - low + 1];
	int index = 0;
	for(int i = low; i <= high; i++)
	{
		if(arr[i] <= arr[part])
			temp[index++] = arr[i];
	}

	
	for(int i = low; i <= high; i++)
	{
		if(arr[i] > arr[part])
			temp[index++] =  arr[i];
	}

	index = 0;
	for(int i = low; i <= high; i++)
		arr[i] = temp[index++];
}


int main()
{
	int size;
	cout << "Enter the size of array\n";
	cin >> size;

	int arr[size];

	cout << "Enter the array elements\n";
	for(int i = 0; i < size; i++)
		cin >> arr[i];


	int low, high, part;
	cout << "Enter the lower point of partition\n";
	cin >> low;

	cout << "Enter the highet point of parition\n";
	cin >> high;

	cout << "Enter the partitiong point\n";
	cin >> part;


	cout << "The array before parition\n";
	for(int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";


	partition(arr, --low, --high, --part);

	cout << "The array after partition\n";
	for(int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";

}