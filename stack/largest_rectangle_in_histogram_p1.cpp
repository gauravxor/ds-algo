/**
 * 
 * Largest Area Possible in a given Histogram
 * 
 * Given a histogram as an array where the elements represents
 * the height of each bar. From the given data return the largest
 * possible area that can be formed using the bars.
 * 
 * INPUT : [2, 1, 5, 6, 2, 3]
 * OUTPUT: 10 (using the bar 5 and 6)
 * 
 * INPUT : [2, 4]
 * OUTPUT: 4
 * 
 * 
 * ALGORITHM (OPTIMIZED USING STACKS)
 * 
 * TC : O(n) | SC : (3N)
 * 
 * Time complexity is made linear still we need three traversals of the array.
 * We need extra space for 2 arrays that will store the previous smaller and
 * next smaller of the current element and a stack to perform the said operations.
 * -------------------------------------------------------------------------------
 * 
 * 
 * First we traverse the array to find the previous smaller element of the current
 * element and store it in a container(array).
 * 
 * We again traveser the array to find the next smaller element of the current
 * element and store it in a container(array).
 * 
 * When the previous smaller and next smaller arrays are generated, we traverse the
 * input array once more and find the area that can be made using the current element
 * using the idea that : 
 * 
 * Area for current element will be equal to
 * (Previous Smaller Element - Next Smaller Position) * Current Element Size
 * 
 * This is still not an efficient approach as we need to do three traversals of the
 * array.
 **/



#include <iostream>
#include <climits>
#include <stack>
using namespace std;


void getPreviousSmaller(int *arr, int *previousSmaller, int size)
{
	stack<int> st;
	st.push(0);

	int index = 0;

	//first element has no leftSmaller so it is assumed to be -1
	previousSmaller[index++] = -1;

	for(int i = 1; i < size; i++)
	{
		while(st.empty() == false && arr[st.top()] >= arr[i])
			st.pop();

		// if stack becomes empty,it means the current element has no
		// smaller element present at its left
		if(st.empty() == true)
			previousSmaller[index++] = -1;
		else
			previousSmaller[index++] = st.top();

		st.push(i);
	}
}



void getNextSmaller(int *arr, int * nextSmaller, int size)
{
	stack<int> st;
	st.push(size - 1);

	int index = size - 1;

	// the last element has not next smaller element so the index is assumed
	// to be the size of the array
	nextSmaller[index--] = size;

	for(int i = size - 2; i >= 0; i--)
	{
		while(st.empty() == false && arr[st.top()] >= arr[i])
			st.pop();

		// if stack becomes empty,it means the current element has no
		// smaller element present at its right
		if(st.empty() == true)
			nextSmaller[index--] = size;
		else
			nextSmaller[index--] = st.top();

		st.push(i);
	}
}


int getMaxArea(int * arr, int size)
{
	int previousSmaller[size];
	int nextSmaller[size];

	getPreviousSmaller(arr, previousSmaller, size);
	getNextSmaller(arr, nextSmaller, size);

	int ans = INT_MIN;

	for(int i = 0; i < size; i++)
	{
		int currentArea = (nextSmaller[i] - previousSmaller[i] - 1) * arr[i];
		ans = max(currentArea, ans);
	}

	return ans;
}


int main()
{
	int size;
	cout << "Enter the size of the array\n";
	cin >> size;

	int arr[size];

	cout << "Enter the array elements\n";
	for(int i = 0; i < size; i++)
		cin >> arr[i];


	int res = getMaxArea(arr, size);
	cout << "Maximum possible area = " << res << "\n";

	return 0;
}