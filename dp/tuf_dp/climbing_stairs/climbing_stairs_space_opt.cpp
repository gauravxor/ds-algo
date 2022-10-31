/**
 * Space optimized version of Counting Stairs Problem
 * 
 * TC : O(n) | SC : O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

int calls = 0;


int countSteps(int n)
{
    if(n <= 2) return n;

    int prev = 2, prevPrev = 1, current = 0;
    
    for(int i = 3; i <= n; i++)
    {
        current = prev + prevPrev;
        prevPrev = prev;
        prev = current;
    }

    return current;
}


int main()
{
    cout << "Enter the number of stairs\n";
    int n;
    cin >> n;

    int ans = countSteps(n);
    cout << "The no. of unique steps is = " << ans << "\n";
    return 0;
}