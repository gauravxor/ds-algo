#include "makeList.h"
using namespace std;

int main()
{
	int nodes;
	cout << "Enter the number of Nodes\n";
	cin >> nodes;

	NODE *head = nullptr;

	int data;
	for (int i = 0; i < nodes; i++)
	{
		cin >> data;
		head = createNode(head, data);
	}

	cout << "The created list is\n";
	printList(head);

	return 0;
}