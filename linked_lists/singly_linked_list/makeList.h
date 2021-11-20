#include <iostream>
using namespace std;
struct NODE
{
	int data;
	NODE * next;
	NODE(int value)
	{
		data = value;
	}
};



NODE * createNode(NODE * headNode, int number)
{
	NODE * newNode = new NODE(number);
	if(headNode == nullptr)
		return newNode;
	
	NODE * currentNode = headNode;
	
	while(currentNode->next != nullptr)
		currentNode = currentNode->next;
	
	currentNode->next = newNode;
	return headNode;
}



void printList(NODE * headNode)
{

	if(headNode == nullptr)
		cout << "Nothing to Print";
	else
	{	
		while(headNode != nullptr)
		{
			cout << headNode->data << " ";
			headNode = headNode->next;
		}
	}

	cout << "\n";
}
