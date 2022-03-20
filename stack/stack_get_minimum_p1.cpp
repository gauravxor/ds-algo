/**
 * Implement a getMin() function in stack that operates in
 * constant time complexity
 *
 * 
 * Algorithm
 * TC : O(1) | SC : O(n)
 * ----------------------------------------------------------- 
 * 
 * 
 * We create another stack to store the minimum elements
 * We perform the following operation while pushing or popping
 * elements from the main stack.
 * 
 * 1) If the minStack is empty or if the element that is being pushed
 * in the stack is smaller or equal than the element in the min stack
 * then we push that element in the minStack.
 * 
 * 2) While popping elements from the main stack, if the element that
 * is being popped, is equal to the HEAD element of the minStack, then we
 * pop that element from minStack too.
 * 
 **/

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> st;
	stack<int> minStack;
	int ch;	
	while(true)
	{
		cout << "Press 1 to push\n";
		cout << "Press 2 to pop\n";
		cout << "Press 3 to get head\n";
		cout << "Press 4 to get min\n";
		cout << "Press anything else to exit\n";

		cin >> ch;
		if(ch == 1)
		{
			int data;
			cout << "Enter the data\n";
			cin >> data;

			st.push(data);
			if(minStack.empty() == true || data <= minStack.top())
				minStack.push(data);
		}
		else
		if(ch == 2)
		{
			if(st.empty() == true)
				cout << "Stack Underflow!!";
			else
			{
				if(st.top() == minStack.top())
					minStack.pop();
				st.pop();
			}
		}
		else
		if(ch == 3)
		{
			if(st.empty() == true)
				cout << "Empty Stack\n";
			else
				cout << st.top() << "\n";
		}
		else
		if(ch == 4)
		{
			if(minStack.empty() == true)
				cout << "Empty stack\n";
			else
				cout << "Min = " << minStack.top() << "\n"; 
		}
		else
			break;
	}
	return 0;
}