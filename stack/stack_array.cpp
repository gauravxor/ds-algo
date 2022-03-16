/** Stack Implementation usign Array */


#include <iostream>
using namespace std;

class stack
{
	int maxSize;  // max size of the stack
	int top;	  // position/count of last data
	int *arr;	  // pointer to array

public:
	stack(int size)
	{
		maxSize = size;
		top = -1;
		arr = new int[maxSize];
	}

	void push(int data);
	void pop();
	int head();  // returns the top data
	int size(); 
	bool isEmpty();
};



void stack::push(int data)
{
	if(top == maxSize)
		cout << "Stack Overflow";
	else
		arr[++top] = data;
}

void stack::pop()
{
	if(top == -1)
		cout << "Stack Underflow\n";
	else
		top--;
}


int stack::head()
{
	if(top == -1)
	{
		cout << "Stack empty\n";
		return -1;
	}
	else
		return arr[top];
}

int stack::size()
{
	return top + 1;
}

bool stack::isEmpty()
{
	return (top == -1);
}



int main()
{
	int size;
	cout << "Enter the max size of the stack\n";
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
			cout << "Enter the data to be pushed\n";
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
			cout << "Head = " << st.head() << "\n";
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
				cout << "Stack Not-Empty\n";
		}
		else
			break;
	}
	return 0;
}
