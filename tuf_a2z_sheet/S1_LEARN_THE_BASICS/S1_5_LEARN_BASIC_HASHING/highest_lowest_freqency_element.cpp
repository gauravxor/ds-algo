#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;
int main()
{
	int size;
	cout << "Enter the size of array\n";
	cin >> size;

	int arr[size];
	unordered_map<int, int> ump;

	cout << "Enter the elements of the array\n";
	for(int i = 0; i < size; i++)
	{
		cin >> arr[i];
		ump[arr[i]]++;
	}

	int high =  0, high_count = INT_MIN;
	int low =  0, low_count = INT_MAX;

	for(auto it : ump)
	{

		if(it.second > high_count)
		{
			high = it.first;
			high_count = it.second;
		}

		if(it.first < low_count)
		{
			low = it.first;
			low_count = it.second;
		}
	}

	cout << high << " is the highest occuring element\n";
	cout << "Occurence count = " << high_count << "\n";

	cout << low << " is the lowest occuring element\n";
	cout << "Occurence count = " << low_count<< "\n";
	return 0;
}