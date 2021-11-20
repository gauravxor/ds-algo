#include "makeList.h"


NODE * reverseList(NODE * headNode)
{
    if(headNode == nullptr || headNode->next == nullptr)
        return headNode;
    

    // we can also remove currentNode and use
    // headNode instead.
    
    NODE * currentNode = headNode;
    NODE * previousNode = nullptr;
    while(currentNode != nullptr)
    {
        NODE * temp = currentNode->next;
        currentNode->next = previousNode;
        previousNode = currentNode;

        currentNode = temp;
    }
    return previousNode;
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
    head = reverseList(head);

    cout << "The reversed list is\n";
    printList(head);
    return 0;
}