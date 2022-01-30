/**
 * Program to find the minimum number of flips needed to
 * make a binary array same. At a time we can select a 
 * single group, containing either 0 or 1 and flip it.
 * The catch is, once we have selected a group of a 
 * particular type we cannot change it i.e if we decided
 * to flips the groups of 1, then we cannot touch any 
 * groups of 0.
 * 
 * INPUT : 0,0,1,1,0,0,1,1,0
 * OUTPUT : From 2 to 3
 *          From 6 to 7
 * 
 * INPUT : 1,0,0,0,1,0,0,1,1,1,1
 * OUTPUT : From 1 to 3
 *          From 5 to 6
 *
 *  
 * ALGORITHM
 * TC : O(n) | SC : O(1)
 * -------------------------
 * Intuition : If the array starts with 0, then the
 * flipping groups of 1 will minimize the flips and 
 * vice versa.
 */


#include <iostream>
using namespace std;

void printFlips(int * arr, int size)
{
    int i;
    for(i=1;i<size;i++)
    {
        if(arr[i]!= arr[i-1])
        {
            if(arr[i]!=arr[0])
                cout << "From " << i << " to ";
            else
                cout << i-1 << "\n";
        }
    }   
    if(arr[size-1]!=arr[0])
        cout << i-1 << "\n";
}

int main()
{
    int size;
    cout << "Enter the size of the array\n";
    cin >> size;

    int arr[size];

    cout << "Enter the array elements\n";
    for(int i=0;i<size;i++)
        cin >>arr[i];
    printFlips(arr, size);
    return 0;
}