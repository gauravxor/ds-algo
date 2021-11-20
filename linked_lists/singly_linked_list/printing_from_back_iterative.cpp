#include "makeList.h"


void printReverse(NODE * headNode)
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

int main()
{
	int nodes;
	cin >> nodes;

	NODE *head = nullptr;

    int data;
	for (int i = 0; i <nodes;i++)
    {
        cin >> data;
        head = createNode(head, data);
    }

    cout << "The original list is\n";
    printList(head);

    cout << "The list printed in reverse Order is\n";
    printReverse(head);
    return 0;
}