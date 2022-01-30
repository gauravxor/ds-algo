/**
 * Given a sorted array containing some elements,we have 
 * to find the index of first occurence of the key element.
 * 
 * Input : 1,1,1,1,1
 *         Key = 1
 * Output : 0
 * 
 * Input : 1,2,2,3,4
 *         Key = 2
 * Output : 1
 * 
 * Algorithm : (Binary Search) (Recursive)
 *-----------------------------------------
 
 * We traverse the array and find any occurence of the key 
 * element. If it is found then we check the following two 
 * conditions :-
 * i) If the current index of key element is 0, then we return
 * that position.
 * ii) If the current index of key element is not 0, then we 
 * check if the previous element is same or not,
 * 
 * If the previous element is not same, we return the current 
 * index or else we binary search the section before the current
 * index.
 */

#include <iostream>
using namespace std;

int findIndex(int * arr, int low, int high, int key)
{
    if(low > high)
        return -1;
    
    int mid = (high + low)/2;
    if(arr[mid] == key)
    {
        if(mid == 0 || (arr[mid-1]!=arr[mid]))
            return mid;
        else 
            return findIndex(arr, low, mid - 1, key);
    }
    else
    if(arr[mid] < key)
        return findIndex(arr,mid+1,high,key);
    else
        return findIndex(arr,low, mid-1, key);
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
    
    int key;
    cout << "Enter the key\n";
    cin >> key;

    int position = findIndex(arr, 0, size, key);
    cout << "The first occuring index is = " << position << "\n";
    return 0; 

}   