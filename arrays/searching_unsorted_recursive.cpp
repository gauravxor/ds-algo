// Recursive Implementation of linear search

#include <iostream>
using namespace std;

// checking is done from the end
int search(int *arr, int index, int key)
{
    if(index>=0)  // if we have not reached top
    {
        if(arr[index]!=key)
            return search(arr,index - 1,key);
        else
            return 1;
    }
    return 0;
}

int main()
{
    int arr[] = {1,2,3,4,5,6};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 1;

    if(search(arr,size - 1,key))
        cout << "Found\n";
    else
        cout << "Not found\n";
    return 0;

}
