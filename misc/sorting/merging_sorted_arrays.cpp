/**
 * Merging two sorted arrays 
 * TC : O(M + N) |  SC : O(M + N)
 * 
 * Where M and N are the size of first
 * and second array respectively.
 * 
 * In this approach we need a third array to 
 * store the end result, as the input arrays
 * will not be having any empty spaces at the 
 * end to store the results.
 * 
**/

#include <iostream>
using namespace std;

int * mergeArrays(int * arr1, int * arr2, int size1, int size2)
{
	int i = 0;
	int j = 0;
	int * x = new int[size1 + size2];
	int curr = 0;
	while(i < size1 && j < size2)
	{
		if(arr1[i] <= arr2[j])
			x[curr++] = arr1[i++];
		else
			x[curr++] = arr2[j++];
	}

	while(i < size1)
		x[curr++] = arr1[i++];
	while(j < size2)
		x[curr++] = arr2[j++];

	return x;
}

int main()
{
	int size1, size2;
    
    cout << "Enter the size of 1st array\n";
    cin >> size1;
    int arr1[size1] = {0};
 	
 	cout << "Enter the elements of first array\n";
    for(int i = 0; i < size1; i++)
        cin >> arr1[i];

    cout << "Enter the size of 2nd array\n";
    cin >> size2;
    int arr2[size2] = {0};

    cout << "Enter the elements of second array\n";
    for(int i = 0; i < size2; i++)
        cin >> arr2[i];

    
    cout << "Two arrays are\n";
    for(int i = 0; i < size1; i++)
    	cout << arr1[i] << " ";
    cout << "\n";

    for(int i = 0; i < size1; i++)
    	cout << arr2[i] << " ";
    cout << "\n";


    int * merged = mergeArrays(arr1, arr2, size1, size2);

    cout << "After merging\n";
    for(int i = 0; i < size1 + size2; i++)
        cout << merged[i] << " ";
    cout << "\n";

    return 0;
}