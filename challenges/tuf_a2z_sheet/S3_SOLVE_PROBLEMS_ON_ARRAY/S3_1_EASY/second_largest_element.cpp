#include <iostream>
#include <climits>
using namespace std;


int getSecondLargest(int *arr, int length)
{
	int largest = arr[0];
	int secondLargest = INT_MIN;


	for(int i = 1; i < length; i++)
	{
		if(arr[i] > largest)
		{
			secondLargest = largest;
			largest = arr[i];
		}
		else
		if(arr[i] < largest && arr[i] != secondLargest)
			secondLargest = arr[i];
	}
	if(secondLargest == INT_MIN)
	{
		cout << "No second largest element found\n";
		return -1;
	}
	return secondLargest;
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

	int secondLargest = getSecondLargest(arr, length);
	
	cout << "The 2nd largest element is = " << secondLargest << "\n";
	return 0;
}