/** Stack Implementation uising LinkedList */

#include <iostream>
using namespace std;

class NODE
{
public:
	int data;
	NODE * next;

	NODE(int val)
	{
		data = val;
		next = nullptr;
	}
};


class stack
{
public:

	NODE *head;
	int maxSize;
	int top;
	stack(int capacity)
	{
		// initially stack is empty so head is set to NULL
		head = nullptr;   
		maxSize = capacity;
		top = -1;  
	}
public:
	void push(int data);
	void pop();
	int peek();
	int size();
	int isEmpty();
};



/**
 * Working of push() operation :
 * 1) Create a new node.
 * 2) Make it point to the last node.
 * 3) Make the last node equal to new node
 */
void stack::push(int val)
{
	if(top == maxSize - 1)
		cout << "Stack Overflow\n";
	else
	{
		NODE *temp = new NODE(val);
		temp->next = head;
		head = temp;
		top += 1;
	}
}


/**
 * Working of pop() operation :
 * 1) Store the next of current node.
 * 2) Delete/free the current node.
 * 3) Make the head point to the node stored in STEP 1.
 */
void stack::pop()
{
	if(top == -1)
		cout << "Stack Underflow\n";
	else
	{
		NODE * temp = head->next;
		delete head;
		head = temp;
		top -= 1;
	}
}

int stack::peek()
{
	if(!isEmpty())
		return head->data;

	return -1;
}

int stack::size()
{
	return top + 1;
}

int stack::isEmpty()
{
	return (top == -1);
}


int main()
{
	int size;
	cout << "Enter the max size of stack\n";
	cin >> size;

	stack st(size);

	
	while(true)
	{
		cout << "Press 1 to push\n";
		cout << "Press 2 to pop\n";
		cout << "Press 3 to get head\n";
		cout << "Press 4 to check size\n";
		cout << "Press 5 to check is empty\n";

		int ch;
		cin >> ch;

		if(ch == 1)
		{
			int data;
			cout << "Enter the data\n";
			cin >> data;
			st.push(data);
		}
		else
		if(ch == 2)
		{
			st.pop();
		}
		else
		if(ch == 3)
		{
			cout << st.peek() << "\n";
		}
		else
		if(ch == 4)
		{
			cout << "Size = " << st.size() << "\n";
		}
		else
		if(ch == 5)
		{
			if(st.isEmpty())
				cout << "Stack Empty\n";
			else
				cout << "Stack have some stuffs\n";
		}
		else
			break;
	}

	return 0;
}