#include <iostream>
using namespace std;

int partition(int * arr, int low, int high)
{
	int pivot = arr[low];
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
			return left;
		swap(arr[left], arr[right]);
	}
}




void quickSort(int * arr, int low, int high)
{
	if(low < high)
	{
		int pivotPos = partition(arr, low, high);
		
		// Hoare's Partition return the actual position of pivot,
		// but it is not sure if the pivot will be present there,
		// so we include the total left half of array
		quickSort(arr, low, pivotPos);
		quickSort(arr, pivotPos + 1, high);
	}
}

int main()
{
	int size;
	cout << "Enter the size of the array\n";
	cin >> size;

	int arr[size];

	cout << "Enter the array elements\n";
	for(int i = 0; i < size; i++)
		cin >> arr[i]; 

	quickSort(arr, 0, size - 1);
	for(int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";
	
	return 0;
}