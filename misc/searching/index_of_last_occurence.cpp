/**
 * Given a sorted array containing some elements,we have 
 * to find the index of first occurence of the key element
 * 
 * Input : 1,1,1,1,1
 *         Key = 1
 * Output : 4
 * 
 * Input : 1,2,2,3,4
 *         Key = 2
 * Output : 2
 * 
 * Algorithm : (Binary Search) (Recursive)
 *-----------------------------------------
 
 * We traverse the array and find any occurence of the key 
 * element. If it is found then we check the following two 
 * conditions :-
 * i) If the current index of key element is the end of the
 * arry then we return that position.
 * ii) If the current index of key element is not the end of
 * the array, then we check if the next element is same or not,
 * 
 * If the next element is not same, we return the current 
 * index or else we binary search the section after the current
 * index.
 */

#include <iostream>
using namespace std;

int findIndex(int * arr, int low, int high, int key)
{
    int mid = 0;
    int size = high;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(arr[mid] == key)
        {
            if(mid == size-1 || arr[mid]!=arr[mid+1])
                break;
            else
                low = mid + 1;
        }
        else
        if(arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }

    if(low > high)
        return -1;
    return mid;
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
    cout << "The last occuring index is = " << position << "\n";
    return 0; 

}   