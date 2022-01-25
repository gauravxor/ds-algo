/**
 * Program to find the majority element of an given array.
 * An element that occurs more than N/2 times where N is 
 * the size of array, then that element is called the 
 * majority element.
 * 
 * Input : 1 2 3 4 5 6
 * Output : -1
 * 
 * Input : 1 2 6 2 2 3 2
 * Output : 2
 * 
 * 
 * Algorithm : (Boyce Moore's Algorithm)
 * TC : O(n) | SC : O(1)
 * ----------------------------------------
 * 
 * The algorithm works in two phases.
 * 
 * In first phase we make the1st element of the array as
 * the candidate element, and check if the other elements
 * are same as the candidate element. If they are same 
 * then we increase the frequency counter of candidate 
 * element or else we decrease it by 1. If the counter
 * becomes 0, then we change the candidate element to 
 * the current element. This is the end of 1st phase.
 * 
 * In second phase we traverse the array again, and find
 * the freqency of the selected candidate element in the
 * 1st phase. If the frequency of the cadidate is greater
 * than N/2, then we return the element or else -1.
 ------------------------------------------------------
 * 
 * INTUITION BEHIND THE ALGORITHM
 * -------------------------------
 * As we know that if the selected candidate is majority
 * then remaining elements are less than N/2.
 * 
 * When the elements are same as the candidate element, 
 * counter is increased(increasing the priority of the
 * candidate) or else decreased.
 * 
 * When counter(priority) becomes 0, this means that there 
 * are same number of different elements(till the current
 * traversed portion),which should not be the case for the 
 * candidate to be the majority element.
 * 
 * Hence we choose the current element as the new candidate 
 * and continue the same till the end. The final candidate will
 * be our majority element. Using the 2nd traversal we confirm 
 * the descision of 1st phase. If it is correct, we consider
 * the selected candidate as the the majority element.
 */


#include <iostream>
using namespace std; 

int findMajority(int * arr, int size)
{
    int candidate = 0;
    int candidateCount = 1;

    for(int i = 1; i < size; i++)
    {
        if(arr[i] == arr[candidate])
            candidateCount++;
        else
            candidateCount--;

        if(candidateCount == 0)
        {
            candidate = i;
            candidateCount = 1;
        }
    }

    candidateCount = 0;
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == arr[candidate])
            candidateCount++;
    }

    if(candidateCount <= size/2)
        return -1;
    
    return arr[candidate];
}


int main()
{
    int size;
    cout << "Enter the size of the array\n";
    cin >> size;

    int arr[size];

    cout << "Enter the elements of the array\n";
    for(int i=0;i<size;i++)
        cin >> arr[i];

    int majorElem = findMajority(arr, size);
    if(majorElem == -1)
        cout << "There is no majority element\n";
    else
        cout << "The majority element is = " << majorElem << "\n";
    return 0;
}