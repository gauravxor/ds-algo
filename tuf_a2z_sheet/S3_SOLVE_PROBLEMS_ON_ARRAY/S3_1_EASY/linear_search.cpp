#include <iostream>
using namespace std;


int linear_search(int *arr, int length, int key)
{
    for(int i = 0; i < length; i++)
    {
        if(arr[i] == key)
            return i + 1;
    } 
    return -1;
}

int main()
{
    int length;
    cout << "Enter the size of the array\n";
    cin >> length;

    int arr[length];

    cout << "Enter the array elements\n";
    for(int i = 0; i < length; i++)
        cin >> arr[i];

    int key;
    cout << "Enter the element to be searched\n";
    cin >> key;

    int key_location = linear_search(arr, length, key);

    if(key_location == -1)
        cout << "Element not found\n";
    else
        cout << "Element found at location " << key_location << "\n";
    return 0;
}