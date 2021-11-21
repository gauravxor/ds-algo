#include "makeList.h"


NODE * removeDuplicates(NODE* headNode)
{
    if(headNode == nullptr || headNode->next == nullptr)
        return headNode;
    
    NODE * currentNode = headNode;

    while(currentNode->next != nullptr)
    {
        if(currentNode->data == currentNode->next->data)
        {
            NODE * tempNode = currentNode->next;
            currentNode->next = currentNode->next->next;
            delete tempNode;
        }
        else
            currentNode = currentNode->next;
    }
    return headNode;
}



int main()
{
    int nodes,data;
    cin >> nodes;

    NODE * head = nullptr;

    for(int i=0;i<nodes;i++)
    {
        cin >> data;
        head = createNode(head,data);
    }

    cout << "The original list is\n";
    printList(head);

    cout << "The list after removing duplicates is\n";
    head = removeDuplicates(head);
    printList(head);
}