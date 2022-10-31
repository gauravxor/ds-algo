#include <iostream>
using namespace std;

void reverse_segment(int *arr, int left, int right)
{
    int segment_length = right - left;

    for(int i = 0; i < segment_length / 2; i++)
        swap(arr[left + i], arr[right - i - 1]);
}

void left_rotate_by_k(int *arr, int length, int k)
{
    k %= length;
    int middle = length - k;
    reverse_segment(arr, 0, middle);
    reverse_segment(arr, middle, length);
    reverse_segment(arr, 0, length);
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

    int k;
    cout << "Enter the number of rotations\n";
    cin >> k;

    cout << "The array after rotation is\n";
    left_rotate_by_k(arr, length, k);

    for(int i = 0; i < length; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}