#include "makeList.h"


// Naive Approach is that, we first find the length
// of the list. If the insert position is within the
// length then traverse through the list again and
// insert the data or else the insert position is
// invalid.


// if the length of the list is N, then accpted values are
// from [1 to N], any other values are considered invalid.

NODE * insertAtK(NODE * headNode, int number, int position)
{
    if(headNode == nullptr || position == 0)
        cout << "List Empty! Cannot Insert\n";
    else
    {
        int counter = 1;
        
        NODE * previousNode = nullptr;
        NODE * currentNode = headNode;

        while(currentNode->next != nullptr && counter < position)
        {
            previousNode = currentNode;
            currentNode = currentNode->next;
            counter++;
        }

        // at this point "previousNode" has Node
        // which should be present just behind the 
        // new inserted Node
        
        // even after traversing the complete list
        // if out insert position is not found, it
        // means we have an invalid insert position
        if(counter != position)
            cout << "Invalid Position Entered\n";
        else
        {
            NODE * newNode = new NODE(number);

            newNode->next = currentNode;
            
            if(previousNode == nullptr) // if insertion is done at HEAD
                headNode = newNode;     // changing the head of the list
            else
                previousNode->next = newNode;  // if insertion is done after HEAD
        }
    }
    return headNode;
}


int main()
{
    int nodes,data,position;
    cin >> nodes;

    NODE * head = nullptr;

    for(int i=0;i<nodes;i++)
    {
        cin >> data;
        head = createNode(head, data);
    }

    cout << "The created list is\n";
    printList(head);
    cout << "\n";

    cout << "Enter the data for insertion\n";
    cin >> data;
    cout << "Enter the position for new data\n";
    cin >> position;

    head = insertAtK(head,data,position);

    cout << "The new list is\n";
    printList(head);

}