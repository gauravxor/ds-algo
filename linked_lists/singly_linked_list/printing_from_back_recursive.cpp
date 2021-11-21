#include "makeList.h"


void printReverse(NODE * headNode)
{
    if(headNode->next != nullptr)
        printReverse(headNode->next);
        
    cout << headNode->data << " ";
    
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

    cout << "The orginal list is\n";
    printList(head);

    cout << "The list printed backward is\n";
    printReverse(head);

}