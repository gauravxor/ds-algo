/** Move all the zeros present in the array to the end.
 *  Note : The order of the numbers should not change
 * 
 *  Input : 1 2 0 0 4 6 0 0 1
 *  Output: 1 2 4 6 1 0 0 0 0
 * --------------------------------
 * 
 * Algorithm 1:
 * -------------
 * Initialize a counter variable to 0, which will be used
 * to keep track of the ocurence of zero while traversal.
 * 
 * Traverse the array and keep on swapping the elements,
 * with the element present at the counter position and
 * increment the counter.
 * 
 * If zero is encountered, don't increment the counter and
 * wait for the next occurence of non zero element. Once it
 * appears, repeat the swap process.
 * ---------------------------------------------------------
 * 
 * Algorithm 2:
 * -------------
 *
 * Initialize a position variable with -1 to store
 * the position of the first zero that appears 
 * in the array while traversal.
 * 
 * Now,
 * Traverse the array and check if the current
 * element is zero and position variable is -1(indicating
 * no zero has been found yet) then make the position
 * variable equal to currentPosition.
 * 
 * Again during traversal if the current element is non zero
 * and position variable is not not equal to -1, then swap
 * the position variable and also increment it by 1.
 * 
 * Repeat the process till the end
 * ----------------------------------------------------------
 **/



#include <algorithm>
#include <iostream>
using namespace std;

void shiftZeroes(int *arr, int size)
{
	// int zeroPos = -1;
	// for(int currentPos = 0; currentPos < size; currentPos++)
	// {
	// 	if(arr[currentPos] == 0 && zeroPos==-1)
	// 		zeroPos = currentPos;
	// 	else
	// 	if(arr[currentPos]!=0 && zeroPos!=-1)
	// 		swap(arr[currentPos],arr[zeroPos++]);
	// }
	
	int zeroCount = 0;
	for(int currentPos = 0; currentPos  < size; currentPos++)
	{
		if(arr[currentPos] != 0)
			swap(arr[currentPos],arr[zeroCount++]);
	}
}
int main()
{
	int size;
	cout << "Enter the size of array\n";
	cin >> size;

	int arr[size];

	cout << "Enter the array elements\n";
	for(int i = 0; i < size; i++)
		cin >> arr[i];

	cout << "The original array\n";
	for(int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";

	shiftZeroes(arr, size);

	cout << "New array\n";
	for(int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";

	return 0;
}
