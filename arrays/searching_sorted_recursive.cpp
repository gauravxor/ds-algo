/** Recursive Implementaion of Binary Search */

#include <iostream>
using namespace std;


int search(int * arr, int low, int high, int key)
{
    int mid = low + (high - low)/2;
    if(low <= high)
    {
        if(arr[mid] == key)
             return 1;
        if(arr[mid] < key)
            return search(arr,mid+1,high,key);
        else
            return search(arr,low,mid-1,key);
    }
    return 0;
}

int main()
{
    int arr[] = {1,2,3,4,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 10;


    if(search(arr,0,size - 1,key))
        cout << "Found\n";
    else
        cout << "Not Found\n";
    return 0;
}