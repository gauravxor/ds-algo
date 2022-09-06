#include <iostream>

using namespace std;
int removeDuplicates(int *arr, int length) 
{
    int index = 0;
    
    for(int i = 1; i < length; i++)
    {
        if(arr[i] != arr[index])
            swap(arr[++index], arr[i]);
    }
    return index + 1;
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

    int index = removeDuplicates(arr, length);
    
    cout << "Dictinct elements are present till " << index << " position\n";

    cout << "The array is\n";

    for(int i = 0; i < length; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}