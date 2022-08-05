#include <iostream>
#include <vector>
using namespace std;
struct NODE
{
	int data;
	NODE * next;
	NODE(int value)
	{
		data = value;
		next = nullptr;
	}
};


// function to make new NODES for the list and
// insert them with the tail

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



void printListBackward(NODE * headNode)
{
	vector<int> v;
	while(headNode != nullptr)
	{
		v.push_back(headNode->data);
		headNode = headNode->next;
	}

	for(auto it = v.rbegin(); it!=v.rend(); it++) 
		cout << *it << " ";
	cout << "\n";
}



NODE * listGen(int size)
{
	NODE * temp = nullptr;
	for(int i = 1; i <= size; i++)
		temp = createNode(temp, i * 10);
	return temp; 
}