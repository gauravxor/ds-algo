/* Input  :  10 20 30 40
*  Output :  20 10 40 30
*
*  Input  :  10 20 30
*  Output :  20 10 30
*
*  Input  :  10
*  Output :  10
*/
#include "makeList.h"

NODE * swapPairs(NODE * headNode)
{
    if(headNode == nullptr || headNode->next == nullptr)
        return headNode;
    
    NODE * currentNode = headNode;

    while(currentNode != nullptr && currentNode->next != nullptr)
    {
        int tempData = currentNode->data;
        currentNode->data = currentNode->next->data;
        currentNode->next->data = tempData; 
        
        currentNode = currentNode->next->next;
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

    cout << "Original List is\n";
    printList(head);

    head = swapPairs(head);

    cout << "Modified List is\n";
    printList(head);
    return 0;

}