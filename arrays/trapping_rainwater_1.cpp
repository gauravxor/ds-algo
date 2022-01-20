/** 
 * TRAPPING RAINWATER PROBLEM_1(USING EXTRA SPACE)
 * 
 * Given an array contating the size of blocks.
 * we have to find the maximum amount of water
 * that can be stored in those blocks.
 * 
 * INPUT : 4 0 6 2 4
 * OUTPUT : 6
 * 
 * INPUT : 5 1 2 3 5
 * OUTPUT : 9
 * 
 * INPUT : 3 3 3 3 
 * OUTUT : 0
 * 
 * 
 * ALGORITM (USING EXTRA SPACE)
 * TC : O(n+n) | SC : O(n) 
 * ----------------------------
 * 
 * First create an array that will contain the
 * maximum size of the block that is present 
 * on the right side of the present block.
 * 
 * After the array is created, traverse the
 * main block size array from left and keep
 * track of the largest block present on the
 * left side of the current block.
 * 
 * Then find the minimum of the leftLargest
 * and rightLarge and subtract the the size of
 * current block from it and add the value to
 * the ANSWER. Repeat the process and return.
 * 
**/

#include <iostream>
#include <climits>
using namespace std;

int trappingWater(int * arr, int size)
{
    int rightMax[size];
    int currentMax = arr[size-1];
    for(int i=size-1;i>=0;i--)
    {
        if(arr[i] > currentMax)
            currentMax = arr[i];
        rightMax[i] = currentMax;
    }

    currentMax = arr[0];
    int trappedWater = 0;
    for(int i=0;i<size;i++)
    {
        if(currentMax < arr[i])
            currentMax = arr[i];
        trappedWater += min(currentMax, rightMax[i]) - arr[i];
    }
    return trappedWater;
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

    int maxWater = trappingWater(arr,size);
    cout << "The max water trapped = " << maxWater << "\n";
    return 0;
}