#include <iostream>
using namespace std;


/**  TC : O(n^2) ,  SC : O(1)*/

int findLargest(int *  arr, int size)
{
    int largest,j;

    for(int i=0;i<size;i++)
    {
        largest = arr[i];
        for(j=i+1;j<size;j++)
        {
            if(arr[i+1] > largest)
                break;
        }
        if(j==size)
            return largest;
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