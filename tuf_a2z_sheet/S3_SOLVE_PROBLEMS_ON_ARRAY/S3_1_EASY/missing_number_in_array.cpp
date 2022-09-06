#include <iostream>

using namespace std;


/**
 * A number XORED with itself given 0.
 * A number XORED with 0 makes no change.
 * 
 *   0 1 2 3 (index)
 * ^ 0 3 2    (elements, here 1 is missing)
 * -----------
 *   0 1 0 
 * -----------
 * And we have our answer. 
**/

int get_missing(int *arr, int length)
{
	int missing = length;

	for(int i = 0; i < length; i++)
	{
		missing = missing ^ i;
		missing = missing ^ arr[i];
	}

	return missing;
}


int main()
{
    int len;
    cout << "Enter the size of array\n";
    cin >> len;

    int arr[len];

    cout << "Enter the array elements of first array\n";
    for(int i = 0; i < len; i++)
        cin >> arr[i];

    cout << "The missing element is ";

    int ans =  get_missing(arr, len);
    cout << ans << "\n";
    return 0;
}