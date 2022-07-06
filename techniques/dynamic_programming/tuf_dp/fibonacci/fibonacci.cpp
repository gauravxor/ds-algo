/**
 * Fibonacci number means, the number at ith position where (i > 2),
 * is equal to the sum of previous and previous previous fibonacci number.
 * 
 * Fibinacci Series
 * (First 10 terms of fibonacci series)
 * 0 1 1 2 3 5 8 13 21 34
 * 
 * 
 * The implementation below is a terrible implementation, where
 * we are repeating the overlapping subproblems in deeper recursive
 * call tree.
 * 
 * To optimize the process we can use a table, where we can store the
 * recently precomputed  values, so that they can be reused instead of 
 * having a recursive call for finding the answer.
 * 
 * This process of array/table is called memoization.
 * Memoization is a Top Down Approach, because here we solve the problem at
 * the highest level first and move down along the path.
 * Memoization is a recursive process, hence it uses some stack space,
 * and that must be taken into consideration while finding the space
 * complexity of the code.
 * 
 * 
 * There is one more method to optimize the process. We can use tables to
 * store the values just like memoization, but this time, we will solve 
 * smallest subproblem first, store it's value in the table, and further
 * use its value to calculate the answer of bigger subproblems as we go
 * ABOVE the path. This method is called tabulation, as it does not uses
 * any recursive calls, and hence there is no stack space present.
 * Tablution is also called Bottom Up Approach, as we start by solving the
 * smallest problem, then solve the bigger subproblems.
 * 
 * In the given code below, the actual position is passed in the
 * recursive call, then it goes down level by level to find the actual
 * answer. It doesnot have any optimization technique to reduce the number
 * of recursive calls.

 */

#include <iostream>
using namespace std;

int calls = 0;

int fibonacci(int n)
{
    // base case (heart of a recursive call)
    if(n <= 2)
        return n - 1;
    
    calls++; // to count the number of recursive calls.

    int prev = fibonacci(n - 1); // get the last value
    int prevPrev = fibonacci(n - 2); // get the 2nd last value

    return prev + prevPrev;
}

int main()
{
    int n;
    cout << "Enter the position for fibonacci\n";
    cin >> n;

    int ans = fibonacci(n);

    cout << "Fibinacci = " << ans << "\n";
    cout << "Total calls = " << calls << "\n";

    return 0;
}