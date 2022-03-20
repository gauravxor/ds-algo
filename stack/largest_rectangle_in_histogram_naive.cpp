/**
 * 
 * Largest Area Possible in a given Histogram
 * 
 * Given a histogram as an array where the elements represents
 * the height of each bar. From the given data return the largest
 * possible area that can be formed using the bars.
 * 
 * INPUT : [2, 1, 5, 6, 2, 3]
 * OUTPUT: 10 (using the bar 5 and 6)
 * 
 * INPUT : [2, 4]
 * OUTPUT: 4
 * 
 * 
 * ALGORITHM (NAIVE)
 * 
 * TC : O(n ^ 2) | SC : (1)
 * -------------------------
 * 
 * We traverse the array and for each element find it's previous and 
 * next smaller element and using that find the area that is possible
 * when we are using the current element. 
 * 
 * 
 * The time complexity is quadratic i.e O(n ^ 2) as we have to travese the array
 * twice for each element (finding the next and previous smaller element)
 *
 **/

#include <iostream>
using namespace std;


int maxArea(int *arr, int size)
{
	int ans = -1;

	for(int i = 0; i < size; i++)
	{
		int current = arr[i];

		// if the previous element is greater than or equal to current
		// element then we will consider it.
		for(int j = i - 1; j >= 0; j--)
		{
			if(arr[j] >= arr[i])
				current += arr[i];
			else
				break;
		}


		// if the next element is greater than or equal to current element
		// then we will consider it.
		for(int j = i + 1; j < size; j++)
		{
			if(arr[j] >= arr[i])
				current += arr[i];
			else
				break;
		}

		ans = max(ans, current);
	}
	return ans;
}


int main()
{
	int size;
	cout << "Enter the size of the array\n";
	cin >> size;

	int arr[size];

	cout << "Enter the array elements\n";
	for(int i = 0; i < size; i++)
		cin >> arr[i];


	int res = maxArea(arr, size);

	cout << "Maximum possible area = " << res << "\n";
	return 0;
}