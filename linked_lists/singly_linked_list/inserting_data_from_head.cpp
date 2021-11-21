#include "makeList.h"


NODE * createNodeHead(NODE * headNode,int number)
{
    NODE * newNode = new NODE(number);
    if(headNode != nullptr)
        newNode->next = headNode;
    return newNode;
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
        head = createNodeHead(head,data);
    }

    cout << "The created list is\n";
    printList(head);
    return 0;
}