#include <iostream>
#include <climits>
using namespace std;

class queue
{
public:
	int front; // for deletion (contains the first inserted element)
	int rear;  // for insertion (contains the last inserted element)
	int size;  // to store the size
	int maxSize;
	int *arr;
	queue(int capacity)
	{
		front = 0; // deletion will be done from front
		rear = 0;
		size = 0;
		maxSize = capacity;
		arr = new int[maxSize];
	}

	void enqueue(int data);  // to push data in queue
	void dequeue();			 // to pop data from queue
	int getFront();			 // to get the top element
	int getSize();		     // to get the size of queue
	int getRear();			 // to get the rear element 
	bool isEmpty();			 // to check if the queue if empty
	bool isFull();			 // to check if qeueu if full
};


void queue::enqueue(int data)
{
	if(isFull())
		cout << "Queue Full\n";
	else
	{
		arr[rear] = data;
		rear = (rear + 1) % maxSize;
		size++;
	}
}

void queue::dequeue()
{
	if(isEmpty())
		cout << "Queue Empty\n";
	else
	{
		front = (front + 1) % maxSize;
		size--;
	}
}

int queue::getSize()
{
	return size;
}


int queue::getFront()
{
	if(!isEmpty())
		return arr[front];
	cout << "Queue is empty\n";
	return INT_MAX;
}

int queue::getRear()
{
	if(!isEmpty())
		return arr[(front + size - 1) % maxSize];
	cout << "Queue is empty\n";
	return INT_MAX;
}


bool queue::isEmpty()
{
	return (size == 0);
}

bool queue::isFull()
{
	return (size == maxSize);
}

int main()
{
	int size;
	cout << "Enter max size of queue\n";
	cin >> size;


	queue q(size);
	int ch;
	while(1)
	{
		cout << "Press 1 to enqueue\n";
		cout << "Press 2 to deque\n";
		cout << "Press 3 to get the front element\n";
		cout << "Press 4 to get the rear element\n";
		cout << "Press 5 to get the size of the queue\n";
		cout << "Press 6 to check if the queue is full\n";
		cout << "Press 7 to check if the queue is empty\n";

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
			if(q.getFront() == INT_MAX)
				cout << "Queue is empty\n";
			else
				cout << "Front Element = " << q.getFront() << "\n";
		}
		else
		if(ch == 4)
		{
			if(q.getRear() == INT_MAX)
				cout << "Queue is empty\n";
			else
				cout << "Rear Element = " << q.getRear() << "\n";
		}
		else
		if(ch == 5)
		{
			cout << "Size = " << q.getSize() << "\n";
		}
		else
		if(ch == 6)
		{
			if(q.isFull())
				cout << "Queue FULL\n";
			else
				cout << "Queue NOT FULL\n";
		}
		else
		if(ch == 7)
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