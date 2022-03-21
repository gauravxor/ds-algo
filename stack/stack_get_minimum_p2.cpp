/** 
 * Implement a getMin() function in stack that operates in
 * constant time complexity
 *
 * 
 * Algorithm
 * TC : O(1) | SC : O(1)
 * ----------------------------------------------------------- 
 * 
 * ASSUMPTIONS MADE : The elements being pushed are POSITIVE.
 * ------------------------------------------------------------
 * 
 * In this implementation we don't create an auxillary stack to
 * store the minimum elements.
 * 
 * Instead keep a variable to store the minimum element.
 * 
 * When we push something in the stack, then if the current element 
 * being pushed is smaller than the current minimum element then we 
 * push the difference of current element(big) and currentMin(small) 
 * in the stack and make the Minimum Element equal to the current element.
 * 
 * This will result in the pushing of a -ve value in the stack which will 
 * denote that at this particular time the value of minimum Element 
 * was modified(a smaller value was pushed in the stack) and that
 * smaller value is currently the minimum element that we pushed(assume).
 * 
 * During the pop() operation, if the element being poppped is positive,
 * then we simply pop it. If the element is negative then we return the 
 * value of current Minimum as that is holding the current value that was
 * pushed in the stack.
 * Then we need to make the minimum element equal to the previous minimum
 * by adding the popped element with the minimum Element and finally pop()
 * that negative value from the stack.
 *
 **/

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> st;
	int minElement;
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

			if(st.empty() == true)
			{
				st.push(data);
				minElement = data;
			}
			else
			if(data < minElement)
			{
				st.push(data - minElement);
				minElement = data;
			}
			else
				st.push(data);
		}
		else
		if(ch == 2)
		{
			if(st.empty() == true)
				cout << "Stack Underflow!!";
			else
			{
				int head = st.top();
				if(head <= 0)
				{
					cout << minElement << " popped\n";
					minElement = minElement - head;
					st.pop();
				}
				else
				{
					cout << head << " popped\n";
					st.pop();
				}
			}
		}
		else
		if(ch == 3)
		{
			if(st.empty() == true)
				cout << "Empty Stack\n";
			else
			{
				if(st.top() <= 0)
					cout << minElement << "\n";
				else
					cout << st.top() << "\n";
			}
		}
		else
		if(ch == 4)
		{
			if(st.empty() == true)
				cout << "Empty stack\n";
			else
				cout << "Min = " << minElement << "\n"; 
		}
		else
			break;
	}
	return 0;
}