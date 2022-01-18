/** Right rotate an array D times.
 * 
 * Input : 1 2 3 4 5 6 
 * D = 2
 * 
 * Output : 5 6 1 2 3 4
 * ----------------------------
 * 
 * Algorithm
 * ----------------------------
 * 1) First reverse the elements from 0 to D
 * (from end i.e. "sizeOfArray - D")
 * 
 * 2) Then reverse the last D elements i.e
 * (sizeOfArray - D) to sizeOfArray
 * 
 * 3) Finally reverse the whole array
 **/

#include <iostream> 
#include <algorithm>
using namespace std;


void reverse(int * arr, int start, int end)
{
    while(start < end)
        swap(arr[start++],arr[end--]);
}

int main()
{
    int size;
    cout << "Enter the size of the array\n";
    cin >> size;

    int arr[size];

    cout << "Enter the array elements\n";
    for(int i=0;i<size;i++)
        cin >> arr[i];


    int rotation;
    cout << "Enter the number of rotations\n";
    cin >> rotation;

    rotation%=size;


    cout << "The original array is\n";
    for(int i=0;i<size;i++)
        cout << arr[i] << " ";
    cout << "\n";

    reverse(arr,0,size-rotation-1);
    reverse(arr,size-rotation,size-1);
    reverse(arr, 0, size-1);



    cout << "The rotated array is\n";
    for(int i=0;i<size;i++)
        cout << arr[i] << " ";
    cout << "\n"; 

}