#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1,2,3,4,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    int key = 1;

    int low = 0, high = size - 1, mid;
    bool found = false;

    while(low <= high)
    {
        // mid = (low+high)/2;
        mid = low + (high - low)/2;
        if(arr[mid] == key)
        {
            found = true;
            break;   
        }
        if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }


    if(found == true)
        cout << "Key found at position " << mid + 1 << "\n";
    else
        cout << "Key not found\n";
    return 0;
}