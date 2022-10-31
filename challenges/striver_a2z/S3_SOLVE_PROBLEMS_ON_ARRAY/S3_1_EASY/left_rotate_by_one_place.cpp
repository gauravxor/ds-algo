#include <iostream>
using namespace std;


void left_rotate_by_1(int *arr, int length)
{
    int lastElement = arr[length - 1];

    for(int i = length - 1; i > 0; i--)
        arr[i] =  arr[i - 1];
    
    arr[0] = lastElement;
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

    cout << "The array after rotation is\n";
    left_rotate_by_1(arr, length);

    for(int i = 0; i < length; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}