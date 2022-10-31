#include <iostream>
using namespace std;

int isSorted(int *arr, int length)
{
	for(int i = 0; i < length - 1; i++)
	{
		if(arr[i] > arr[i + 1])
			return false;
	}
	return true;
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

	if(isSorted(arr, length))
		cout << "Array is sorted\n";
	else
		cout << "Array is not sorted\n";

	return 0;
}