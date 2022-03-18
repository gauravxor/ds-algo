/** 
 * Implementation of two stacks in array.
 * Constraints -> There should be no wastage of space.
**/

#include <iostream>
using namespace std;

class stack
{
public:
	int maxSize;
	int leftTop;
	int rightTop;
	int * arr;

	stack(int capacity)
	{
		maxSize = capacity;
		leftTop = -1;
		rightTop = maxSize;
	}

	void push1(int data);
	void push2(int data);

	void pop1();
	void pop2();

	int size1();
	int size2();

	int head1();
	int head2();

	bool isEmpty1();
	bool isEmpty2();

	void print();

};


void stack::push1(int data)
{
	if(leftTop + 1 == rightTop)
		cout << "Stack Overflow\n";
	else
		arr[++leftTop] = data;
}


void stack::push2(int data)
{
	if(leftTop + 1 == rightTop)
		cout << "Stack Overflow\n";
	else
		arr[--rightTop] = data;
}


void stack::pop1()
{
	if(leftTop == -1)
		cout << "Stack Underflow\n";
	else
	{
		arr[leftTop] = -1;
		leftTop--;
	}
}


void stack::pop2()
{
	if(rightTop == maxSize)
		cout << "Stack Underflow\n";
	else
	{
		arr[rightTop] = -1;
		rightTop++;
	}
}


int stack::size1()
{
	return leftTop + 1;
}

int stack::size2()
{
	return maxSize - rightTop;
}


int stack::head1()
{
	if(!isEmpty1())
		return arr[leftTop];
	return -1;
}

int stack::head2()
{
	if(!isEmpty2())
		return arr[rightTop];
	return -1;
}


bool stack::isEmpty1()
{
	return (leftTop == -1);
}

bool stack::isEmpty2()
{
	return (rightTop == maxSize);
}

void stack::print()
{
	cout << "Stack content right now is\n";
	for(int i = 0; i < maxSize; i++)
		cout << arr[i] << " ";
	cout << "\n";
}


int main()
{
	cout << "Enter the size of the array\n";
	int size;
	cin >> size;

	stack st(size);

	
	while(true)
	{
		cout << "Press 1 to push\n";
		cout << "Press 2 to pop\n";
		cout << "Press 3 to get head\n";
		cout << "Press 4 to check size\n";
		cout << "Press 5 to check is empty\n";
		cout << "Press 6 to print stack space\n";

		int ch;
		cin >> ch;

		if(ch == 1)
		{
			int data;
			cout << "Enter the data\n";
			cin >> data;
			cout << "Press 1 to push in stack 1\n";
			cout << "Press 2 to push in stack 2\n";
			cin >> ch;
			if(ch == 1)
				st.push1(data);
			else
				st.push2(data);
		}
		else
		if(ch == 2)
		{
			cout << "Press 1 to pop from stack 1\n";
			cout << "Press 2 to pop from stack 2\n";
			cin >> ch;
			if(ch == 1)
				st.pop1();
			else
				st.pop2();
		}
		else
		if(ch == 3)
		{
			cout << "Press 1 to get head of stack 1\n";
			cout << "Press 2 to get head of stack 2\n";
			cin >> ch;
			if(ch == 1)
				cout << "Head = " << st.head1() << "\n";
			else
				cout << "Head = " << st.head2() << "\n";
		}
		else
		if(ch == 4)
		{
			cout << "Press 1 to get size of stack 1\n";
			cout << "Press 2 to get size of stack 2\n";
			cin >> ch;
			if(ch == 1)
				cout << "Size of stack1 = " << st.size1() << "\n";
			else
				cout << "Size of stack2 = " << st.size2() << "\n";

		}
		else
		if(ch == 5)
		{
			cout << "Press 1 to check if stack1 is empty\n";
			cout << "Press 2 to check if stack2 is empty\n";
			cin >> ch;
			if(ch == 1)
			{
				if(st.isEmpty1())
					cout << "Stack 1 is empty()\n";
				else
					cout << "Stack 1 is having some stuffs\n";
			}
			else
			{
				if(st.isEmpty2())
					cout << "Stack 2 is empty()\n";
				else
					cout << "Stack 2 is having some stuffs\n";
			}
		}
		else
		if(ch == 6)
			st.print();
		else
			break;
	}
	return 0;
}