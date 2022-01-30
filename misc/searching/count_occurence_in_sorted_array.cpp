/**
 * Given an sorted array, we have to return the
 * number of occurence of a given key element.
 * 
 * Input : 1 2 2 3 3 4
 *         Key : 3
 * Output : 2
 * 
 * Input : 1 2 3 3 4
 *       Key : 5
 * Output : 0
 * 
 * 
 * Algorithm (Binary Search)
 * --------------------------
 * The normal process is to find the first and the
 * last ocurence of the element in the array using 
 * binary search and then return (lastPosition - 
 * firstPostion + 1)
 * 
 */




#include <iostream>
using namespace std;

int findLeft(int * arr, int size, int key)
{
    int low = 0;
    int high = size - 1;
    int mid;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(arr[mid] == key)
        {
            if(mid == 0 || arr[mid-1]!=arr[mid])
                return mid;
            else
                high = mid - 1;
        }
        else
        if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1; 
    }
    return -1;
}


int findRight(int * arr, int size, int key)
{
    int low = 0;
    int high = size - 1;
    int mid;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(arr[mid] == key)
        {
            if(mid == size - 1 || arr[mid+1]!=arr[mid])
                return mid;
            else
                low = mid + 1;
        }
        else
        if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1; 
    }
    return -1;
}



int main()
{
    int size;
    cout << "Enter the number of array elements\n";
    cin >> size;

    int arr[size];

    cout << "Enter the array elements\n";
    for(int i=0;i<size;i++)
        cin >> arr[i];
    
    int key;
    cout << "Enter the key element\n";
    cin >> key;


    int leftIndex = findLeft(arr, size, key);
    int rightIndex = findRight(arr, size, key);
    if(leftIndex == -1 || rightIndex == -1)
        cout << "The key appeared 0 times\n";
    else
        cout << "The key appeared " << rightIndex - leftIndex + 1 << " times\n";
    return 0;
}