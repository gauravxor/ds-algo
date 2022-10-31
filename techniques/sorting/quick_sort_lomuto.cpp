#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &v, int low, int high)
{
	int pivot = v[high];
	int pivotIndex = low - 1;

	for(int i = low; i <= high - 1; i++)
	{
		if(v[i] < pivot)
			swap(v[++pivotIndex], v[i]);
	}
	swap(v[++pivotIndex], v[high]);
	return pivotIndex;
}

void quickSort(vector<int> &v, int low, int high)
{
	if(low < high)
	{
		int pivotPos = partition(v, low, high);
		
		// As Lomuto Partiton returns the actual position of
		// the pivot, so we need to partiton the complete
		// left and right part of array.
		quickSort(v, low, pivotPos - 1);
		quickSort(v, pivotPos + 1, high);
	}
}

int main()
{
	int size;
	cout << "Enter the size of the array\n";
	cin >> size;

	vector<int> v(size, 0);

	cout << "Enter the array elements\n";
	for(int i = 0; i < size; i++)
		cin >> v[i];

	quickSort(v, 0, size - 1);

	for(int i = 0; i < size; i++)
		cout << v[i] << " ";
	return 0;
}