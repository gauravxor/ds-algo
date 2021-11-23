#include "makeList.h"


// In this process we call the function recursively to the
// get last node and use that node to link link with the 
// remaining N-1 nodes.
// 
// To put it in simple way, list starts getting reversed from 
// the back (i.e job is done while retuninig back to the main
// caller of the function)
// 
// Input : 10 20
// Output: 20 10
NODE * reverseList(NODE * headNode)
{
    if(headNode == nullptr || headNode->next == nullptr)
        return headNode;

    // reversedNode will have the starting node of the 
    // reversed List i.e. 20
    NODE * reversedNode = reverseList(headNode->next);

    // headNode is 10 so 10's next is 20 and 20's next is
    // NULL, so we change it to headNode i.e 10;
    headNode->next->next = headNode;

    // headNode is 10 so changing its next pointer to NULL.
    headNode->next = nullptr;
    
    return reversedNode;
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

    head = reverseList(head);
    
    cout << "The reversed list is\n";
    printList(head);

    return 0;
}