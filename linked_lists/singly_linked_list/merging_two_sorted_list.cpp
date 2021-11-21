#include "makeList.h"


NODE * mergeSorted(NODE * headNode1, NODE * headNode2)
{
    if(headNode1 == nullptr)
        return headNode2;
    if(headNode2 == nullptr)
        return headNode1;
    
    // here we set the first node of merged list
    NODE * newNode = nullptr;    
    if(headNode1->data <headNode2->data)
    {
        newNode = headNode1;
        headNode1 = headNode1->next;
    }
    else
    {
        newNode = headNode2;
        headNode2 = headNode2->next;
    }


    NODE * tempNode = newNode;  // to keep track of tail
    while(headNode1 != nullptr && headNode2 != nullptr)
    {
        if(headNode1->data < headNode2->data)
        {
            tempNode->next = headNode1;
            headNode1 = headNode1->next;   
        }
        else
        {
            tempNode->next = headNode2;
            headNode2 = headNode2->next;
        }
        tempNode = tempNode->next;
    }

    // connecting the remainings of any list 
    // with the merged list's tail.
    
    if(headNode1!=nullptr)
        tempNode->next = headNode1;
    else
        tempNode->next = headNode2;

    return newNode;
}




int main()
{
    int firstSize, secondSize,data;
    
    cin >> firstSize;
    cin >> secondSize;
    
    NODE * head1 = nullptr;
    NODE * head2 = nullptr;

    // inserting values in List 1
    for(int i=1;i<=firstSize;i++)
    {
        cin >> data;
        head1 = createNode(head1,data);
    }

    // inserting values in List 2
    for(int i=1;i<=secondSize;i++)
    {
        cin >> data;
        head2 = createNode(head2,data);
    }

    cout << "The first list is\n";
    printList(head1);
    cout << "\n";

    cout << "The second list is\n";
    printList(head2);
    cout << "\n";

    head1 = mergeSorted(head1,head2);
    cout << "The merged list is\n";
    
    printList(head1);
    cout << "\n";

    return 0;
}