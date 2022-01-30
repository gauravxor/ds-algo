/**
 * Given an array containing some integer elements. We
 * have to find the equilibrium point.
 * 
 * The element of the array whose sum of elements of left
 * and right side is equal,is called the equilibrium point
 * of the array.
 * 
 * Input : 4 -2 -2
 * Output : Equilibrium Point Exists.
 * 
 * Input : 1 2 3 4 3 2 1
 * Output : Equilibrium Point Exists.
 * 
 * 
 * Algorithm (Prefix Sum Technique)
 * TC : O(n) | SC : (n)
 * -------------------------------------------------
 * 
 * First we generate the prefix sum array and from there
 * we answer the query for sums.
 * The answer for sum queries can be given as:
 * 
 * 1) If the left and the right portion of current element 
 * are equal then it means that we are dealing with the 
 * corner elements.
 * 
 * 2) If the left range is zero, then it means that we are
 * dealing with the left side of the current element.
 * 
 * 3) If the left range is not zero, it means that we are 
 * dealing with the right size of the current element.
 * In this case the end or the RIGHT of the query is
 * constant.
 * 
 * 
 * After getting the left and right sum of the current
 * element we compare the two values and of they are same
 * then we have found the equilibrium element.
 */

#include <iostream>
using namespace std;

void generate_prefix(int * prefix_sum, int * arr,int size)
{
    prefix_sum[0] = arr[0];
    for(int i=1;i<size;i++)
        prefix_sum[i] = prefix_sum[i-1] + arr[i];
}


// There can be two range sums i.e. left and right.
// We can have separate function to find the sums
// but here I have written a single function to 
// answer queries.
int findSum(int * prefixSum, int left, int right)
{
    if(left == right)
        return 0;

    if(left == 0)
        return prefixSum[right - 1];
    else
        return prefixSum[right-1] - prefixSum[left-1];
}


int findEquilibrium(int * arr, int * prefix_sum, int size)
{
    for(int i=0;i<size;i++)
    {
        int leftSum = findSum(prefix_sum, 0, i);
        int rightSum = findSum(prefix_sum, i+1,size);
        if(leftSum == rightSum)
            return 1;
    }
    return 0;
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

    int prefix_sum[size];
    generate_prefix(prefix_sum, arr, size);

    if(findEquilibrium(arr, prefix_sum, size) == 1)
        cout << "Equilibrium point exists\n";
    else
        cout << "Equilibrium point does not exists\n";
    return 0;
}