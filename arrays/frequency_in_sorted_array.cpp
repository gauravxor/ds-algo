/** Print the frequency of each element of a sorted array
 * 
 * Input : 10 20 30 30 40
 * Output: 10 = 1
 *         20 = 1
 *         30 = 2
 *         40 = 1
 * ------------------------
 * 
 * ALGORITHM
 * -----------
 * Make a counter varibale initialized to 1.
 * 
 * Start traversing the array from the 2nd element.
 * If it matches with the previous element then
 * increment the counter by 1 or else print the
 * previous element and the value of the counter as
 * the frequency.
 * 
 * CORNER CASE
 * ------------
 * If all the elements of the array are same, then
 * the above mentioned condtion will never become 
 * true, so we need to make sure that, this case is
 * handled.
 * 
 * So do handle this, we just print whatever value is 
 * present in the counter variable at the end of the
 * for loop.
 * ------------------------------------------------------
*/

#include <iostream>
using namespace std;

void printFreq(int *  arr, int size)
{
    int counter = 1;
    int i;
    for(i=1;i<size;i++)
    {
        if(arr[i-1] == arr[i])
            counter++;
        else
        {
            cout << arr[i-1] << " = " << counter << "\n";
            counter = 1;
        }
    }
    cout << arr[i-1] << " = " << counter << "\n";
}

int main()
{
    int size = 0;
    cout << "Enter the size of the array\n";
    cin >> size;

    int arr[size];

    cout << "Enter the array in sorted order\n";
    for(int i=0;i<size;i++)
        cin >> arr[i];

    printFreq(arr,size);
    return 0;
}