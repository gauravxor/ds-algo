#include <algorithm>
#include <iostream>
using namespace std;
void shiftZeroes(int *arr, int size)
{
	// 1 2 0 6 4 0 5
	// 1 2 6 0 4 0 5
	// 1 2 6 4 0 0 5
	int x;
	int posZero = -1;
	for (int currentPos = 0; currentPos < size; currentPos++)
	{
		if (arr[currentPos] == 0 && posZero == -1)
			posZero = currentPos;
		else if (posZero != -1 && arr[currentPos] != 0)
		{
			swap(arr[currentPos], arr[posZero]);
			posZero++;
		}
	}
}
int main()
{
	int size;
	cout << "Enter the size of array\n";
	cin >> size;

	int arr[size];

	cout << "Enter the array elements\n";
	for (int i = 0; i < size; i++)
		cin >> arr[i];

	cout << "The original array\n";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";

	shiftZeroes(arr, size);

	cout << "New array\n";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";

	return 0;
}
