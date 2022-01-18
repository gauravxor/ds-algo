/** Find the maximum value of arr[j] - arr[i], 
 *  where j > i.
 * 
 * Input : 2 3 10 6 4 8 1
 * Output: 8
 * 
 * Input : 7 9 5 6 3 2
 * Output: 2
 * 
 * 
 * ALGORITHM
 * -----------
 * 
 * Assume that the max difference is difference between
 * 1st and 2nd element. We also assume that the first
 * element is the smallest element in the array.
 * 
 * Now we traverse the array and keep on finding the
 * minimum element and subtracting it from the current
 * element of the array. If the result is greater than
 * the previous max then we store the value and keep on
 * traversing and return the maximum value.
 * ------------------------------------------------------
 * 
 **/

#include <iostream>
using namespace std;

int maxDifference(int * arr, int size)
{
    int ans = arr[1] - arr[0];
    int minVal = arr[0];
    for(int i=1; i<size; i++)
    {
        ans = max(ans, arr[i] - arr[0]);
        minVal = min(arr[i], minVal);
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
    for(int i=0;i<size;i++)
        cin >> arr[i];

    cout << "Max Difference = " << maxDifference(arr, size) << "\n";
    return 0;
}