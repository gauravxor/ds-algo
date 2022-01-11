#include <ctime>
#include <iostream>
using namespace std; 
int main()
{
    int arr[]={1,4,3,2,56,6,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 56,i;

    bool found = false;
    for(i=0;i<size;i++)
    {
        if(arr[i] == key)
        {
            found = true;
            break;
        }
    }
    if(found == true)
        cout << "Key found at position" << i+1 << "\n";
    else
        cout << "Key not found\n";
    return 0;
}
