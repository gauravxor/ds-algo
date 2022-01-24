#include <iostream>
using namespace std;

int maxOnes(int * arr, int size)
{
    int count = 0;
    int ans = 0;
    for(int i=0;i<size;i++)
    {
        if(arr[i] == 1)
            ans = max(ans, ++count);
        else
            count = 0;
    }
    return  ans;
}

int main()
{
    int size;
    cout << "Enter the size of the array\n";
    cin  >> size;

    int arr[size];

    cout << "Enter the array elements\n";
    for(int i=0;i<size;i++)
        cin >> arr[i];

    int ones = maxOnes(arr, size);
    cout << "Maximum consecutive ones = " << ones << "\n";
    return 0;

}