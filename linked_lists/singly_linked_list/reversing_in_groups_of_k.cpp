#include "makeList.h"

/** The task is to reverse the given list in groups of K, where K is the size of the
 *  group. If K = 1, then return the original list and if K is equal to or greater 
 *  than the size of given list then reverse the complete list.
 * -------------------------------------------------------------
 * Input : 10 20 30 40 50 60
 *         K = 2
 * Output: 20 10 40 30 60 50
 * -----------------------------
 * Input : 10 20 30 40 50 60
 *         K = 4
 * Output: 40 30 20 10 60 50 
 * ------------------------------
 * Input : 10 20 30 40 50 60
 *         K = 7
 * Output: 60 50 40 30 20 10
 * ------------------------------
 * 
 * 
 * Algorithm:
 * -----------
 * 1) First reverse the links of first K nodes. When reversing is done for the first time,
 * then the headNode(to be retured) must be equal to the first Kth Node in the linked list.
 * Example: Input : 10 20 30 40   and K = 2
 * Then the modified list will always start from the first Kth Node i.e. 20.
 * 
 * 
 * 2) Before starting to reverse, store the starting node from where the reversing
 * process began. We need this node to connect to the next group of revesed nodes.
 * So we store the starting point i.e 10, in a variable.
 * 
 * 3) After the reversing the 1st K nodes, change the HeadNode to the first Node of
 * the reversed segment.
 * After this step, the "headNode" is pointing to 20, i.e [20->10->NULL] 
 * 
 * 4) Store the last node of the 1st K reversed nodes somewhere(initially make it NULL), 
 * to use it to connect to the first node of the next reversed segment. 
 * Last node of reversed segment i.e. 10 is stored.
 * 
 * Make a checking, if after reversing the current group, do we need to make a connection
 * i.e. in the code I used "toConnect" for this task. If "toConnect" is carrying something 
 * then make the connection, else move to the next iteration
 * 
 * 5) When reversing the 2nd group, connected the last node of 1st segment stored in 
 * "toConnect" of that segment with the starting of the new reversed segment.
 * 
 * REPEAT THE PROCESS UNTIL YOU REACH AN END AND VIOLA!! JOB DONE 
 */

NODE * modifyList(NODE * headNode,int k)
{
    NODE * toConnect = nullptr;
    NODE * currentNode = headNode;
    NODE * startingNode = nullptr;

    bool isFirst = true;

    while(currentNode != nullptr)
    {
        NODE * previousNode = nullptr;
        startingNode = currentNode;
        int count = 1;

        while(currentNode != nullptr && count <= k)
        {
            NODE * nextNode = currentNode->next;
            currentNode->next = previousNode;
            previousNode = currentNode;
            currentNode = nextNode;
            count++;
        }

        if(isFirst == true)
        {
            headNode = previousNode;
            toConnect = startingNode;
            isFirst = false;
        }
        else
        if(toConnect != nullptr)
        {
            toConnect->next = previousNode;
            toConnect = startingNode;
        }
    }
    return headNode;
}


int main()
{
    int nodes;
    vector<int> v;
    v.resize(10);
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
    cout << "Enter the value of K\n";
    int k;
    cin >> k;

    cout << "The modified list is\n";
    head = modifyList(head,k);

    printList(head);
    return 0;
}