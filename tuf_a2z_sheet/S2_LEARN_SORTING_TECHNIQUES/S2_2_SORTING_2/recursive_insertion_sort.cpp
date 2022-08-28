#include <iostream>
using namespace std;

static int count = 0;


void insertion_sort_main(int *arr, int length)
{
	if(length <= 1)
		return;

	insertion_sort_main(arr, length - 1);

	int lastElement = arr[length - 1];
	int firstIndex = length - 2;

	while(firstIndex >= 0 && arr[firstIndex] > lastElement)
	{
		arr[firstIndex + 1] = arr[firstIndex];
		firstIndex--;
	}
	arr[firstIndex + 1] = lastElement;
}

int main()
{
	int length;
	cout << "Enter the size of the array\n";
	cin >> length;

	int arr[length];

	cout << "Enter the elements of the array\n";
	for(int i = 0; i < length; i++)
		cin >> arr[i];

	insertion_sort_main(arr, length);

	cout << "The sorted array is\n";
	for(int i = 0; i < length; i++)
		cout << arr[i] << " ";
	cout << "\n";

	cout << "COUNT = " << count << "\n";
	return 0;
}