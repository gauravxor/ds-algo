/** Leaders in an array means the elements which are
 * strictly greater than all the elements to their
 * right side.
 * 
 * Input : 7 10 4 3 6 5 2
 * Output: 10 6 5 2 (order doesnot matter)
 * 
 * ALGORITHM
 * -----------
 * 
 * Create a MAX variable to store the maximum value
 * till the traversed array.It is initialized with 
 * minimum possible value. 
 * We traverse the array from right to left and find
 * the elements which are greater than the value stored
 * in MAX(initially lowest value is stored). If such 
 * value is found, it is stored in max and we print max 
 * (that has the current value) at the same time.
 * 
**/


#include <iostream>
#include <climits>
using namespace std;


void printLeaders(int * arr, int size)
{
    int max = INT_MIN;
    for(int i=size-1;i>=0;i--)
    {
        if(arr[i]>max)
        {
            cout << arr[i] << " ";
            max = arr[i];
        }
    }
    cout << "\n";
}

int main()
{
    int size;
    cout << "Enter the size of the array\n";
    cin >> size;

    int arr[size];

    cout << "Enter the elements of the array\n";
    for(int i=0;i<size;i++)
        cin >> arr[i];

    printLeaders(arr,size);
    return 0;
} 