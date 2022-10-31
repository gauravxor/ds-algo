/** 
 * Implementation of Insertion Sort
 * 
 * Algorithm :
 * ------------
 * TC : O(n^2) | SC : O(1)
 * Pick an element at index = 1 and comapre it with the elements before 
 * it. If the selected element is smaller then swap or else leave it in 
 * its position or else. Keep doing this till the end.
 * 
 * Again pick an element from index = 2 and repeat the above step.
 * At the end we will have the sorted array with us.
 * 
 */

#include <iostream>
using namespace std;

void insertionSort(int * arr, int size)
{
    for(int i = 1; i < size; i++)
    {
        int j = i;
        while(j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j - 1], arr[j]);
            j--;
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

    insertionSort(arr, size);

    cout << "After sorting\n";
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}