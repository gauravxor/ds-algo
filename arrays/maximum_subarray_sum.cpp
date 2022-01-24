/**
 * Program to find the sum of maximum contagious, subarray
 * 
 * Input : -5 1 -2 3 -1 2 -2
 * Output: 4 
 * 
 * Algorithm : (KADANE'S)
 * TC : O(n) | SC : O(1)
 * ----------------------
 * 
 */
#include <iostream>
using namespace std;

int maxSum(int * arr,int size)
{
    int maxTillNow = arr[0];
    int sum = arr[0];
    for(int i=1;i<size;i++)
    {
        sum = max(sum + arr[i], arr[i]);
        maxTillNow = max(maxTillNow, sum);
    }
    return maxTillNow;
}

int main()
{
    int size;
    cout << "Enter the size of the array\n";
    cin >> size;

    int arr[size];
    cout << "Enter the elements in the array\n";
    for(int i=0;i<size;i++)
        cin >> arr[i];

    int ans = maxSum(arr, size);
    cout << "The maximum subarray sum is = " << ans << "\n";
    return 0;
}