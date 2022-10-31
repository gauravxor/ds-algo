#include <iostream>
#include <unordered_map>
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

	cout << "The frequency data is\n";
	for(auto it : ump)
		cout << it.first << " occured " << it.second << " times\n";
	return 0;
}