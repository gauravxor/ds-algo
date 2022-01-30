/** 
 * Find the sqaure root of a given number, without
 * using library function i.e. sqrt().
 * 
 * Input : 16
 * Output : 4
 * 
 * Input : 100000
 * Output: 316 (lower bound)
 * 
 * 
 * Algorithm (Binary Search)
 * TC : O(n) | SC : O(1)
 * -------------------------------
 * 
 * We take the number N and find the middle of the number
 * from 0 to N. If the square of the middle portion is 
 * higher than the given number then we binary search the
 * lower range or else we binary search the upper range.
 * 
 */


#include <iostream>
using namespace std;

int findRoot(int num)
{
    long long low = 0;
    long long high = num;
    long long mid = 0;
    while(low <= high)
    {
        mid = (low + high)/2;
        long long square = mid * mid;
        if(square == num)
            return mid;
        else
        if(square < num)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return mid - 1;

}
int main()
{
    int num;
    cout << "Enter the number for square root\n";
    cin >> num;

    int root = findRoot(num);
    cout << "Square root = " << root << "\n";
    return 0;
}