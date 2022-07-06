/**
 * In the code given below, we are using a table to store the
 * precomputed values of smaller subproblems, but here we are 
 * starting from the bigger problem and moving towards the smaller
 * problems. When we are able to solve the smaller subproblem then
 * we store the answer in a table, and that value will be used by
 * the bigger problem later on, in the recursive call trees.
 * 
 * This method prevent the recomputing of the value of a subproblem
 * if it is solved already and this technique is called memoization.
 * As we start solving the problem from TOP level and go towards the
 * GROUND level and then COME BACK to TOP level, this process is also
 * called the TOP DOWN APPROACH.
 * 
 * Memoization is a recursive process hence the use of stack space
 * is present. As old values are reused, this method trememdously 
 * reduces the number of recursive calls.
 */

#include <iostream>
#include <vector>
using namespace std;

int calls = 0;

int fibonacci(int n, vector<int> &dp)
{
    if(n <= 2)
        return dp[n];
    
    calls++;

    if(dp[n] != 0)
        return dp[n];
        
    int prev = fibonacci(n - 1, dp);
    int prevPrev = fibonacci(n - 2, dp);

    dp[n] = prev + prevPrev; 
    return dp[n];
}

int main()
{
    int n;
    cout << "Enter the position for fibonacci\n";
    cin >> n;

    vector<int> dp(n + 1, 0);
    dp[2] = 1; 

    int ans = fibonacci(n, dp);

    cout << "Fibinacci = " << ans << "\n";
    cout << "Total calls = " << calls << "\n";

}