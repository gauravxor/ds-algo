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


class queue
{
public:
	NODE * front;
	NODE * rear;
	int size;

	queue()
	{
		front = nullptr;
		rear = nullptr;
		size = 0;
	}

	void enqueue(int val);
	void dequeue();

	void getFront();
	void getRear();
	int getSize();

	bool isEmpty();

};


void queue::enqueue(int val)
{
	NODE * temp = new NODE(val);
	if(front == nullptr)
		front = rear = temp;
	else
	{
		rear->next = temp;
		rear = temp;
	}
	size++;
}

void queue::dequeue()
{
	if(isEmpty())
		cout << "Queue Empty\n";
	else
	{
		NODE * temp = front;
		front = front->next;
		delete temp;
		size--;
	}
}



void queue::getFront()
{
	if(isEmpty())
		cout << "Queue Empty\n";
	else
		cout << front->data << "\n";
}


void queue::getRear()
{
	if(isEmpty())
		cout << "Queue Empty\n";
	else
		cout << rear->data << "\n";
}

int queue::getSize()
{
	return size;
}


bool queue::isEmpty()
{
	return (size == 0);
}



int main()
{
	queue q;
	int ch;
	while(1)
	{
		cout << "Press 1 to enqueue\n";
		cout << "Press 2 to deque\n";

		cout << "Press 3 to get the front element\n";
		cout << "Press 4 to get the rear element\n";
		cout << "Press 5 to get the size of the queue\n";

		cout << "Press 6 to check if the queue is empty\n";

		cin >> ch;

		if(ch == 1)
		{
			int data;
			cout << "Enter the data\n";
			cin >> data;
			q.enqueue(data);
		}
		else
		if(ch == 2)
		{
			q.dequeue();
		}
		else
		if(ch == 3)
		{
			q.getFront();
		}
		else
		if(ch == 4)
		{
			q.getRear();
		}
		else
		if(ch == 5)
		{
			cout << "Size = " << q.getSize() << "\n";
		}
		else
		if(ch == 6)
		{
			if(q.isEmpty())
				cout << "Queue EMPTY\n";
			else
				cout << "Queue NOT EMPTY\n";
		}
		else
			break;
	}
	return 0;
}