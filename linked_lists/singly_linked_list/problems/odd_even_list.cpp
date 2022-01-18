/** https://leetcode.com/problems/odd-even-linked-list/
 *  
 *  Given a linkedlist, combine the odd and even elements.
 *  
 *  Input  : 1->2->3->4->5
 *  Output : 1->3->5->2->4
**/
 
#include "../makeList.h"


NODE * combine(NODE * headNode)
{
    NODE * evenHead = nullptr;
    NODE * oddHead = nullptr;


    NODE * tempOdd = nullptr;
    NODE * tempEven = nullptr;

    while(headNode != nullptr)
    {
        int data = headNode->data;

        if(data%2==0)
        {
            if(evenHead == nullptr)
            {            
                evenHead = headNode;
                tempEven = evenHead;
            }
            else
            {
                evenHead->next = headNode;
                evenHead = evenHead->next;
            }
        }
        else
        {
            if(oddHead == nullptr)
            {
                oddHead = headNode;
                tempOdd = oddHead;
            }
            else
            {
                oddHead->next = headNode;
                oddHead = oddHead->next;
            }
        }
        headNode = headNode->next;
    }

    evenHead = nullptr;
    cout << "Even list is\n";
    printList(tempEven);
    cout << "\n";

    cout << "Odd List is\n";
    printList(tempOdd);
     cout << "\n";

    // return nullptr;
    if(oddHead == nullptr)
         tempOdd = evenHead;
    else
        oddHead->next = evenHead;
    return tempOdd;
}

int main()
{
    int nodes;
    cout << "Enter the number of nodes\n";
    cin >> nodes;

    NODE * head = nullptr;

    int data;
    cout << "Enter the data\n";
    for(int i=0;i<nodes;i++)
    {
        cin >> data;
        head = createNode(head,data);
    }

    cout << "The original list is\n";
    printList(head);

    head = combine(head);

    cout << "The modifies list is\n";
    printList(head);

    return 0;
}