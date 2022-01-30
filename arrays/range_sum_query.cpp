/** Given an array consisting some integers and a range 
 *  L-R (Left and Right). We have to return the sum of 
 *  all the elements present betweem the range(inclusive).
 * 
 * Input : 1 2 3 4 5 6
 *         L = 1  R = 3
 * Output:  
 * 
 * Algorithm (Prefix Sum Technique)
 * TC : O(n) | SC : O(n)
 * Extra space is needed to store the prefix sum array
 * ----------------------------------------------------
 * 
 * First we generate the prefix sum array and from there
 * we answer the query for sums.
 * The answer for sum queries can be given as:
 * 
 * 1) If the LEFT portion is zero, then we will directly
 * return the prefix sum till the right element.
 * 
 * 2) If the LEFT portion is not zero then we subtract the
 * prefix sum till the element BEHIND the LEFT portion and
 * subtract it from the prefix sum till the right element.
 *  
 */



#include <iostream>
using namespace std;

void generate_prefix(int * prefix_sum, int * arr,int size)
{
    prefix_sum[0] = arr[0];
    for(int i=1;i<size;i++)
        prefix_sum[i] = prefix_sum[i-1] + arr[i];
}


int findRangeSum(int * prefix_sum, int start, int end)
{
    if(start == 0)
        return prefix_sum[end];
    return prefix_sum[end] - prefix_sum[start - 1];
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


    int start, end;
    cout << "Enter the starting point\n";
    cin >> start;

    cout << "Enter the ending point\n";
    cin >> end;

    int prefix_sum[size];
    generate_prefix(prefix_sum, arr, size);


    int ans = findRangeSum(prefix_sum, start, end);
    cout << "The range sum is = " << ans << "\n";

    return 0;
}