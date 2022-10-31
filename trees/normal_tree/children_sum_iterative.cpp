/** 
 * Code to check if CHILDREN SUM PROPERTY hold in a given
 * binary tree.
 * 
 * Children Sum Property : If the root of the tree or it's subtree is
 * equal to the sum of the "data" of its left and right child, then
 * children sum property holds for that binary tree.
 * 
 * Assumptions Made : If any child is NULL, then it's data is taken 0.
 * 
 * 
 * Approach : Iterative
 * TC : O(n) | SC : O(n)
 * --------------------------
 * 
 * Do a level order traversal and for each Node, check, if it's data
 * is equal to its left and right child. If equal, push the right and
 * left child in the queue for further processing, or else break out 
 * from the loop and end the execution.
 **/

#include "tree.h"

bool children_sum(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while(q.empty() == false)
    {
        Node * currentNode = q.front();
        q.pop();

        // if the currentNode has both left and right child
        if(currentNode->lchild != nullptr && currentNode->rchild != nullptr)
        {
            // if the property doesnot exists
            if(currentNode->data != (currentNode->lchild->data + currentNode->rchild->data))
                return false;

            // pushing the left and right child in the queue for further processing
            q.push(currentNode->lchild);
            q.push(currentNode->rchild);

        }
        else  // if only left child of the Node exists
        if(currentNode->lchild != nullptr && currentNode->rchild == nullptr)      
        {
            if(currentNode->data != currentNode->lchild->data)
                return false;
            q.push(currentNode->lchild);
        }
        else // if only right child of the Node exists
        if(currentNode->lchild == nullptr && currentNode->rchild != nullptr)
        {
            if(currentNode->data != currentNode->rchild->data)
                return false;
            q.push(currentNode->rchild);
        }
    }
    return true;
}


int main()
{
    Node * root = create();

    if(children_sum(root))
        cout << "Property Exists\n";
    else
        cout << "Property Doesnot Holds\n";

    return 0;
}
