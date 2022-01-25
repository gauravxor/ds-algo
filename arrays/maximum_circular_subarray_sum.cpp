/**
 * Program to find the maximum sum of a circular subarray.
 * 
 * Input :  5 -2 3 4
 * Output: 12
 * 
 * Input : 2 3 -4
 * Output: 5
 * 
 * Input : 3 -4 5 6 -8 7
 * Output: 17
 * 
 * ALGORITHM
 * TC : O(n) | SC : O(1) 
 * ----------------------
 * 
 * Find the maximum of normal subarray sum and then find 
 * the minimum subarray sum and subtract it from the total 
 * sum of the array elements and return the maximum of the 
 * two values.
 * 
 * To find the minumum subarray sum, we invert the array 
 * elements and then use kadane algorithm to find the max
 * sum, as this max sum will actually be the minumum sum of 
 * the non ineverted array. (Benefit of this technique is that
 * we dont have to rewrite a modified Kadane's Algorithm).
 * 
 */

#include <iostream>
using namespace std;

int kadane(int * arr, int size)
{
    int currentMax = arr[0];
    int maxSum = arr[0];
    for(int i=1;i<size;i++)
    {
        currentMax = max(arr[i], currentMax + arr[i]);
        maxSum = max(maxSum, currentMax);
    }
    return maxSum;
}

int findSum(int * arr, int size)
{
    int normalSum = kadane(arr, size);
    if(normalSum < 0)
        return normalSum;

    int arraySum = 0;
    for(int i=0;i<size;i++)
    {
        arraySum += arr[i];
        arr[i] *= -1;
    }    

    int maxCircular = arraySum + kadane(arr, size);
    return max(maxCircular, normalSum);
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

    int maxSum = findSum(arr, size);
    cout << "The max Sum is = " << maxSum << "\n";
    return 0;
}