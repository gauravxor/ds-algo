/**
 * Merging two sorted arrays without creating a third
 * array for storing the result
 *  
 * Where N and M are the sizes of first and second array
 * respectively.
 * 
 * Here any of the input arrays will contain some extra 
 * space for the extra elements that will be added after
 * the merge is done.
 * 
 * 
 * Algorithm: (INPLACE)
 * 
 * TC : O(N + M) : SC : (1)
 * ---------------------------
 * 
 * Start comparing the elements of both the input arrays
 * from the END and store the greater one at the end of
 * the array that contains the EXTRA SPACE for the end 
 * results. 
 *  
 * NO NEED TO RETURN ANYTHING AS THE ALGORITHM MERGES THE
 * INPUT ARRAYS, INPLACE.
 * 
**/


#include <iostream>
using namespace std;


void mergeArrays(int * arr1, int * arr2, int size1, int size2)
{
	int i = size1 - 1;
	int j = size2 - 1;
	int curr = size1 + size2 - 1;
	while(i && j)
	{
		if(arr1[i] <= arr2[j])
			arr2[curr--] = arr1[i--];
		else
			arr2[curr--] = arr2[j--];
	}

	while(i)
		arr2[curr--] = arr1[i--];
	while(j)
		arr2[curr--] = arr2[j--];
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
    int arr2[size1 + size2] = {0};

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


    mergeArrays(arr1, arr2, size1, size2);

    cout << "After merging\n";
    for(int i = 0; i < size1 + size2; i++)
        cout << arr2[i] << " ";
    cout << "\n";

    return 0;
}