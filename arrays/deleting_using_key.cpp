#include <iostream>
using namespace std;

int del(int * arr, int size, int key)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(arr[i]==key)
            break;
    }
    if(i==size)
        return 0;
    for(int j=i;j<size-1;j++)
        arr[j] = arr[j+1];
    return 1;
}


int main()
{
    int capacity = 5, size = 4, key  = 1;
    int arr[5] = {1,2,3,4};
    
    if(del(arr,size,key))
    {
        cout << "The new array is\n";
        size--;
        for(int i=0;i<size;i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
    else
        cout << "Key not found\n";
    
    return 0;
}