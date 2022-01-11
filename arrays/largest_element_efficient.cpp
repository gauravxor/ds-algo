#include <iostream>
using namespace std;


/**  TC : O(n)  */

int findLargest(int *  arr, int size)
{
    int largest = arr[0];
    for(int i=1;i<size;i++)
    {
        if(arr[i]>largest)
            largest = arr[i];
    }
    return largest;
}
int main()
{
    int size;
    cout << "Enter size\n";
    cin >> size;

    int arr[size];

    cout << "Enter the elements\n";
    for(int i=0;i<size;i++)
        cin >> arr[i];

    int largest = findLargest(arr,size);
    cout << "The largest element is " << largest << "\n";
    return 0;
}