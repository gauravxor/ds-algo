#include <iostream>
using namespace std;

int appears_once(int *arr, int length)
{
	int ans = 0;
	for(int i = 0; i < length; i++)
		ans ^= arr[i];

	return ans;
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

	int ans = appears_once(arr, length);
	cout << "Number at appears once is = " << ans << "\n";


	return 0;
}