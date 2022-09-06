#include <iostream>
using namespace std;


int getMax(int *arr, int length)
{
	int largest = arr[0];
	for(int i = 1; i < length; i++)
		largest = max(largest, arr[i]);

	return largest;
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

	int largest = getMax(arr, length);
	
	cout << "The largest element is = " << largest << "\n";
	return 0;
}