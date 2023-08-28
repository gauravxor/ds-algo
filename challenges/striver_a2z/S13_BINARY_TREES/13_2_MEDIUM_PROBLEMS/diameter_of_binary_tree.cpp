#include "binary_tree.h"

/**
 *  Brute force approach where we find the height of each left and right subtree of a given
 *  node, find the diameters and take the maximum one.
 *
 *  This is a top down approach, because we start finding answer from the top and keep on
 *  calculating till the leaf ndoes.
 *
 *  TC : O(N * N)
 *  Traversing through all the N nodes twice. One to find the diameter and one to find the height.
 *
 *  SC : O(N)
 *  If the tree is skewed, then at max N recursive calls will be made, taking up stack space.
*/
void getDiameter(Node *root, int &diameter) {
    if(root == nullptr) {
        return;
    }
    /** Getting the height of left subtree */
    int leftSubtreeHeight = getHeight(root->left);
    /** Getting the height of right subtree */
    int rightSubtreeHeight = getHeight(root->right);

    /** Calculating the diameter of the current node */
    int newDiameter = leftSubtreeHeight + rightSubtreeHeight;
    /** Taking the max diameter */
    diameter = max(newDiameter, diameter);

    /** Recursively checkiing the diamter of left child of current Node, hoping to find a better diameter */
    getDiameter(root->left, diameter);
    /** Recursively checkiing the diamter of right child of current Node hoping to find a better diameter */
    getDiameter(root->right, diameter);
}


/**
 *  Optimal Approach
 *  Bottom Up Apprach, where we first go to lead node and from there calculate answers and go all the way
 *  to the top and return the appropriate answer.
 *
 *  Here we find the height of the left and right subchild in same recursive calls.
 *  Once we have the height of subchild, we find the diameter and store it.
 *
 *  TC : O(N)
 *  Traversal is done only once, for all N nodes, because we are not recalculating the heights again.
 *
 *  SC : O(N)
 *  If the tree is skewed, then at max N recursive calls will be made, taking up N stack space.
 *
**/

int getDiameter_2(Node *root, int &diameter) {
    if(root == nullptr) {
        return 0;
    }
    /** Recursively getting the left child's diameter */
    int leftSubtreeHeight = getDiameter_2(root->left, diameter);
    /** Recursively getting the right child's diameter */
    int rightSubtreeHeight = getDiameter_2(root->right, diameter);

    /** Once all the recursive calls are done for a node, we reach the leaf node and find it's diameter*/
    int newDiameter = leftSubtreeHeight + rightSubtreeHeight;
    diameter = max(diameter, newDiameter);

    /** Retuning the height of leaf node at the end of the recursive call. This height will be carry forwarded
     *  and will be used to find the diameter of parent nodes.
    **/
    return max(leftSubtreeHeight, rightSubtreeHeight) + 1;
}


int main () {
    Node *rootNode = createTree();
    int diameter = 0;
    getDiameter_2(rootNode, diameter);
    cout << "Diameter = " << diameter<< "\n";
    freeMemory(rootNode);
    return 0;
}