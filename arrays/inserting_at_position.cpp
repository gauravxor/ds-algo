/** Inserting a new element in array at a given position 
 * 
 * [ALGORITHM]
 * 
 * 1) Check if there is space to insert in the array 
 * 2) If there is space, run a loop from end to the 
 *    insert position, and shift the elements to the right.
 *    Doing this will create an available space at the given
 *    position.
 * 3) Finally insert the data in the available positon.
 * 
 * 
 *   If Capacity = 5, Position = 2 ,Size = 3 and Array = 1,2,3,X,X
 *   X represents empty cells, then
 * 
 *                   0 1 2 3 4 5 (index)
 *   Shifted Array = 1,2,2,3,X 
 *   Now position 2 or 1(zero based indexing) becomes free.
 *   Insert the new element at that position, and the final
 *   array becomes 1,Y,2,3,X (Y represents new data).
**/


#include <iostream>
using namespace std;


int insert(int * arr, int capacity, int size, int pos,int data)
{
    if(size+1 < capacity)  //checking space  
    {
        // shifting elements to the right
        for(int i=capacity-1; i>=pos; i--) 
            arr[i] = arr[i-1];

        // final insertion is made
        arr[pos-1] = data;
        return 1;
    }
    else
        return 0;
}

int main()
{
    int capacity = 5, size = 3, data = 10, pos = 1;
    int arr[5] = {1,2,3};

    if(insert(arr, capacity, size, pos, data))
    {
        cout << "New array\n";
        for(int i=0;i<capacity;i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
    else
        cout << "Insufficient Capacity\n";
    return 0;
}