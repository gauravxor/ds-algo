/** Program to find the second largest element 
 * 
 * [ALGORITHM]
 * 
 * 1) Initialize the currentLargest with the first element 
 *    of the array and secondLargest with -1(or some)
 * 
 * 2) If any element is greater than the currentLargest,
 *    move the currentLargest to secondLargest and, put 
 *    the newLargest in the currentLargest.
 * 
 * 3) If any element is not greater than the currentLargest
 *    then check two conditions
 * 
 *    i) If the current element is equal. (if equal then
 *       skip, as we cannot make secondLargest same as the
 *       largest one)
 * 
 *   ii) If not then check if secondLargest is -1 or not.
 *       (to check if some number came into it or not)
 *       If it is -1 or if nextLargest is less than 
 *       currentNumber, then change the nextLargest to
 *       the currentNumber.
 
 **/
#include <iostream>
using namespace std;

int secondLargest(int * arr, int size)
{
    int largest = arr[0];
    int nextLargest = -1;

    for(int i=1;i<size;i++)
    {
        if(largest < arr[i])
        {
            nextLargest = largest;
            largest = arr[i];
        }
        else
        if(arr[i]!=largest)
        {
            if(nextLargest == -1 || nextLargest < arr[i])
                nextLargest = arr[i];
        }
    }
    return nextLargest;
}


int main()
{
    int size;
    cout << "Enter the size\n";
    cin >> size;

    int arr[size];

    cout << "Enter the elements\n";

    for(int i=0;i<size;i++)
        cin >> arr[i];

    int nextLargest = secondLargest(arr,size);
    cout << "Second Largest = " << nextLargest << "\n";
    return 0;
}