/**
 * Program to find the length of longest contigious subarray
 * such that it contains alternative odd and even elements.
 * 
 * For example, if we start traversing an array and find 
 * a odd element then it's next element should be even
 * and it's next should be odd and vice versa.
 * 
 * Input : 5 10 20 6 3 8
 * Output: 3 [6 3 8]
 * 
 * Input : 1 2 3 4 5 6
 * Output : 6 [Complete array is of our type]
 * 
 * Algorithm [Kadane's]
 * TC : O(n) | SC : O(1)
 * ----------------------
 * 
 * We will traverse the arry and apply Kadane's algorithm.
 * Just will we add a conditon that if the current and the 
 * previous element is alternating then only increment the
 * counter.
 */

#include <iostream>
using namespace std;


int alternating(int * arr, int size)
{
    int counter = 1;
    int maxLength = 1;

    for(int i=1;i<size;i++)
    {
        if((arr[i]%2==0 && arr[i-1]%2!=0) || (arr[i]%2!=0 && arr[i-1]%2==0))
            maxLength = max(maxLength, ++counter);
        else
            counter = 1;
    }
    return maxLength;
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
    
    int maxLength = alternating(arr, size);
    cout << "The max length = " << maxLength << "\n";
    return 0;
}