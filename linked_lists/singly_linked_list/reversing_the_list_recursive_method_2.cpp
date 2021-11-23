#include "makeList.h"

// In this process, we keep in revsering the links
// as we move forward through the list. Here the 
// function have nothing to do while returning time.
//
// This process is just the opposite of process 1.

NODE * reverseList(NODE * headNode, NODE * previousNode)
{
    if(headNode == nullptr)
        return previousNode;

    // storing the next node of currentNode
    NODE * nextNode = headNode->next;

    // linking the currentNode's NEXT to it's previousNode 
    headNode->next = previousNode; 

    return reverseList(nextNode,headNode);  
}


int main()
{
    int nodes;
    cin >> nodes;
    
    NODE * head = nullptr;

    int data;
    for(int i=0;i<nodes;i++)
    {
        cin >> data;
        head = createNode(head,data);
    }

    cout << "The original list is\n";
    printList(head);

    head = reverseList(head,nullptr);
    
    cout << "The reversed list is\n";
    printList(head);

    return 0;
}