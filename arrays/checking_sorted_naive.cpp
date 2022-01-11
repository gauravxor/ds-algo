#include <iostream>
using namespace std;

int isSorted(int (&arr)[6], int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]>=arr[j])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int arr[] = {1,2,3,5,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);

    if(isSorted(arr,size))
        cout << "Array is sorted\n";
    else
        cout << "Array is not sorted\n";
    return 0;
}