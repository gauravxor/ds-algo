#include <iostream>
using namespace std;


void move_zeroes(int *arr, int length)
{
    int index = 0;
    for(int i = 0; i < length; i++)
    {
        if(arr[i] != 0)
            swap(arr[index++], arr[i]);
    }
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

    cout << "The array after moving zeroes to end is\n";
    move_zeroes(arr, length);

    for(int i = 0; i < length; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}