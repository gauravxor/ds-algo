/**
 * Given a sorted array of infinite length, we have to
 * search for a given key in the array efficiently.
 * 
 * Practically, infinite array means, that an array, that
 * contains a lot of element (say millions) and the 
 * index of search is biased toward left side.
 * 
 * Algorithm (Binary Search)
 * TC : O(position) | SC : O(1)
 * -------------------------------------
 * 
 * We traverse the array from the beginnig and keep
 * on checking three things :-
 * i) If the current element is equal then return the
 * index of the element.
 * ii) If the current element is less than the key,
 * then we know that if the key is present in the array
 * then it must be on the right side of the current element.
 * So we increment the next search position by "currentPos*2;"
 * 
 * iii) If the current element is greater than key then we
 * know that we have moved past the key element and if the
 * key is present in the array, then it must be present
 * in the left side of the current element. THIS CONDITION
 * IS THE STOPPING CONDITION.
 * 
 * After we have reached a stopping condition, we just have to
 * binary search from the index "currentPosition/2+1" to
 * "currentPosition-1". 
 * 
 */

#include <iostream>
using namespace std;

int getEndPoint(int * arr, int size, int key)
{
    if(arr[0] == key)
        return 0;
    int currentIndex = 1;

    while(arr[currentIndex] <= key)
    {
        if(arr[currentIndex] == key)
            return currentIndex;
        else
            currentIndex *= 2;
    }
    return currentIndex;
}


int binarySearch(int * arr, int low, int high, int key)
{
    int mid;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(arr[mid] == key)
            return mid;
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
    cout << "Enter the size of the array\n";
    cin >> size;

    int arr[size];

    cout << "Enter the array elements\n";
    for(int i=0;i<size;i++)
        cin >> arr[i];
    
    int key;
    cout << "Enter the key\n";
    cin >> key;

    int endPoint = getEndPoint(arr, size, key);

    if(arr[endPoint] == key)
        cout << "Element exists at index " << endPoint << "\n";
    else
    {
        int position = binarySearch(arr, endPoint/2+1, endPoint-1, key);
        if(position == -1)
            cout << "Element doesnot exists\n";
        else
        cout << "Element exists at index " << position << "\n";

    }
        return 0;
}