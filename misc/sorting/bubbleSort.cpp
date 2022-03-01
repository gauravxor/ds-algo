/** 
 * Implementation of Bubble Sort
 * 
 * Algorithm :
 * ------------
 * TC : O(n^2) | SC : O(1)
 * Pick an element at index = 0 and check if it is the smallest
 * element.(from the rest of the array). If it is, leave it in its
 * position or else, swap it with the new smaller element. 
 * Keep doing this till the end of the array.
 * 
 * Again pick an element from index = 1 and repeat the above step.
 * At the end we will have the sorted array with us.
 * 
 */

#include <iostream>
using namespace std;

void bubbleSort(int * arr, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(arr[j] < arr[i])
                swap(arr[i], arr[j]);
        }
    }
}

int main()
{

    int size;
    cout << "Enter the size of the array\n";
    cin >> size;

    int arr[size];
    cout << "Enter the array elements\n";
    for(int i = 0; i < size; i++)
        cin >> arr[i];
    
    cout << "Before sorting\n";
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";

    bubbleSort(arr, size);

    cout << "After sorting\n";
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}