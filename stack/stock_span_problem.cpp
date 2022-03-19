/** 
 * Stock Span Problem
 * 
 * Given an array consisting of stock prices at
 * each individual day. We have to print the span of each
 * stock. Span of stock is the number of CONSECUTIVE stocks
 * whose prices have been smaller or equal to the current 
 * stock.
 * 
 * INPUT : 13 15 12 14 16 8 6 4 10 30
 * OUTPUT: 1  2   1  2  5 1 1 1  4 10
 * 
 * INPUT : 10 20 30 40
 * OUTPUT: 1  2  3  4
 * 
 * 
 * ALGORITHM
 * TC : O(n) |  SC : O(n) [Stack Space]
 * ------------------------
 * We have the naive algorithm where we check the span of each stock
 * individually which takes O(n^2) worst and average case and O(1) 
 * auxillary space.
 * 
 * To solve the problem in linear runtime we can use STACKS.
 * 
 * The main formula to get the span of the elements is
 * 
 * If there is an element greater than the current element, then
 * 		Span = Current Index - Index of Nearest Greater Element
 * 
 * else
 * 		Span = currentIndex + 1  (+1 as we include the current element)
 * 
 * 
 * The span of first element is always 1 so we explicitly push it in
 * the stack. Now traverse the input array from the 2nd element and
 * compare it with the elements of the stack. If the current top of stack is
 * less than the current element then pop that element or else break.
 * 
 * Now if after the above operation, the stack becomes empty, then that means
 * all of the elements present at the right side are smaller than the current
 * element. So we handle these cases (line 28) and push the current element in
 * the stack.
 * 
 **/
#include <iostream>
#include <stack>
using namespace std;


void stockSpan(int *arr, int size)
{
	stack<int> st;
	st.push(0);   // puhsing the first index
	cout << 1 << " ";

	for(int i = 1; i < size; i++)
	{
        // checking if the elements in the stack is smaller
        // than the current element.
		while(st.empty() == false && arr[st.top()] <= arr[i])
			st.pop();

		if(st.empty() == true)
			cout << i + 1 << " ";
		else
			cout << i - st.top() << " ";

		st.push(i);
	}
    cout << "\n";
}

int main()
{
	int size;
	cout << "Enter the size of the array\n";
	cin >> size;

	int arr[size];

	for(int i = 0; i < size; i++)
		cin >> arr[i];
	
	stockSpan(arr, size);	
	
	return 0;
}