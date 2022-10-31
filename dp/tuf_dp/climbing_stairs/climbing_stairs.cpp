/**
 * https://leetcode.com/problems/climbing-stairs/
 * 
 * The main intuition here to sovle the problem is that
 * if we take one step forward then let say we are left with [X STEPS]
 * and if we take two steps forward then we are left with [Y STEPS]. 
 * The then total number of steps that could be taken after taking
 * either one or two steps, is the sum of [X and Y].
 * 
 * The base case being that, if there are only two stairs that need to be
 * climbed then we dont need any recursive calls, as we already know the
 * answer.
 * 
 *  This is basically a problem of fibonacci numbers.
 * 
 * 
 *  TC : O(n) |  SC : O(n) (Auxillary Stack Space)
 */

#include <iostream>
#include <vector>
using namespace std;

int calls = 0;

// basic recursive approach
int countSteps(int n)
{
    // if we have only two stairs to take, then
    // we already know the answer, so we return
    if(n <= 2) return n;
    
    // otherwise 
    // we 1st find the no. of steps for (n - 1) stairs.
    int oneStep = countSteps(n - 1);
    
    // then we find the no. of steps for (n - 2) stairs.
    int twoStep = countSteps(n - 2);
    

    return oneStep + twoStep;
}


int main()
{
    cout << "Enter the number of stairs\n";
    int n;
    cin >> n;

    int ans = countSteps(n);

    cout << "The no. of unique steps is = " << ans << "\n";
    cout << "Total recursive calls = " << calls << "\n";
    return 0;
}