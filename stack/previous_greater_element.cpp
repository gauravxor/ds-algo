/**
 * Previous Greater Element
 * 
 * Given an array, we need to print the position wise previous
 * greater element.
 * 
 * INPUT : 13 15 12 14 16  8 6 4 10 30
 * OUTPUT: -1 -1 15 15 -1 16 8 6 16 -1
 *
 * 
 * 
 * ALGORITHM
 * TC : O(n) | SC : O(n) [Auxillary Stack Space]
 * -------------------------------------------------
 * We have the naive algorithm where we can find the previous greater
 * elemment which takes O(n^2) worst case and average case TC and O(1) 
 * auxillary space.
 * 
 * To solve the problem in linear runtime we can use STACKS.
 * 
 * 
 * The previous greater of 1st element is always -1 so we explictly push the first
 * element in the stack. Now traverse the input array from the 2nd element and
 * compare it with the elements of the stack. If the current top of stack is
 * less than the current element then pop that element or else break.
 * 
 * Now if after the above operation, the stack becomes empty, then that means
 * all of the elements present at the left side are smaller than the current
 * element and there is not greater element so we print -1 or else we print the
 * stack top.
 *
 **/ 

#include <iostream>
#include <stack>
using namespace std;
int main()
{
	int size;
	cout << "Enter the size of the array\n";
	cin >> size;

	int arr[size];

	for(int i = 0; i < size; i++)
		cin >> arr[i];


	stack<int> st;
	st.push(arr[0]);

	cout << "-1 ";  // previous greater of first element is always -1

	for(int i = 1; i < size; i++)
	{
		while(st.empty() == false && st.top() <= arr[i])
			st.pop();

		// if the stack is empty, it means no greater element is present in 
		// the left side.
		if(st.empty() == true)
			cout << "-1 ";
		else
			cout << st.top() << " ";
		
		// pushing the current element in the stack as now after doing the above
		// operations the current greater will be the current element.
		st.push(arr[i]);
	}
	cout << "\n";
	return 0;
}