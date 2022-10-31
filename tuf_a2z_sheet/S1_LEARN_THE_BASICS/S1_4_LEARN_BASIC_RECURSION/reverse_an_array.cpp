#include <iostream>
using namespace std;

void reverse_array(int *arr, int leftIndex, int rightIndex)
{
	if(leftIndex > rightIndex)
		return;

	swap(arr[leftIndex],arr[rightIndex]);
	reverse_array(arr, leftIndex + 1, rightIndex - 1);
}

int main()
{
	int length = 0;
	cout << "Enter the size of the array\n";
	cin >> length;

	int arr[length];
	cout << "Enter the array elements\n";
	for(int index = 0; index < length; index++)
		cin >> arr[index];

	reverse_array(arr, 0, length - 1);

	cout << "The reversed array is\n";
	for(int val: arr)
		cout << val << " ";
	cout << "\n";

	return 0;
}