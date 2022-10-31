#include <iostream>
using namespace std;

static int count = 0;


// standard version, derived from iterative implementation
// this version is also not optimised, and uses a lot of
// stack space
/**
void bubble_sort_rec(int *arr, int i, int j, int length)
{
	count++;
	if(i < length)
	{
		if(j < length - i - 1)
		{
			if(arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
			bubble_sort_rec(arr, i, j + 1, length);
		}
		else
			bubble_sort_rec(arr, i + 1, 0, length);
	}
	else
		return;	
}
**/

// TC : O(n ^ 2) | SC : O(n)

void bubble_sort_main(int *arr, int length)
{
	count++;

	if(length <= 1)
		return;

	for(int i = 0; i < length - 1; i++)
	{
		if(arr[i] > arr[i + 1])
			swap(arr[i], arr[i + 1]);
	}

	bubble_sort_main(arr, length - 1);
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

	bubble_sort_main(arr, length);

	cout << "The sorted array is\n";
	for(int i = 0; i < length; i++)
		cout << arr[i] << " ";
	cout << "\n";

	cout << "COUNT = " << count << "\n";
	return 0;
}