/**
 * https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003
 * 
 * This is an excellent problem on 2D DP.
 * The idea behind solving this problem is that, we have to find
 * all the possible ways to plan the schedule and then find the 
 * maximum merit points from the calculated results.
 * 
 * Let say we are having, the following grid
 * 
 * 2 5 3
 * 7 3 6
 * 1 3 5
 * 
 * To solve this problem, we will first consider 2 located at index [0][0]
 * then move to 2nd day(row). There as we have selected 2, we cannot select
 * 7, so we take 3 and move to 3rd day. Then in third day, we select
 * either 1 or 5 from the 3rd row, as we cannot take 3(adjacent row element
 * is selected in previous step). From the selection we take the maximum and 
 * give it back to 3(at 2nd row). Than again at 2nd row we take 6 and repeat
 * the same process again and return the maximum of result back to 1st row.
 * At this we have checked for all the possible combinations for 2 at [0][0],
 * and now we will do the same for the rest of the elements of the first row.
 * 
 * 
 * The complete approach is recursive, hence
 * TC : O() | SC : O(3 x N)[for input] + O(n) [stack space]
 *  
 *
 * */


#include <iostream>
#include <vector>
#include <climits>

using namespace std;
unsigned long long int calls = 0;

int getMax(int row, int lastPos, vector<vector<int>> &points)
{
    // if we have reached the last row(day), then we have to take
    // the maximum of the SUITABLE element from the current row.
    // To the SUITABLE element will be one, whose column wise adjacent
    // element is not taken in the previous step.
    // 
    // The 2nd case is that, if the current row is the only row in the table
    // then we don't need to check for the SUITABLE element, and we have 
    // to return the maximum of 3 elements;
    
    calls++;
    if(row == 0)
    {
        // now we have to check for SUITABLE element from the points table.
        int maxPoint = INT_MIN;
        for(int pos = 0; pos < 3; pos++)
        {
            if(pos != lastPos)
                maxPoint = max(maxPoint, points[row][pos]);
        }
        return maxPoint;
    }

    int maxPoint = 0;


    for(int pos = 0; pos < 3; pos++)
    {
        // checking for the suitable element
        if(pos != lastPos)
        {
            // if we find a suitable element, then we take that element
            // and make a recursive call for the next row, and repeat
            // the same process of selecting a SUITABLE element and 
            // calling for the rows at lower levels.
            int mx = points[row][pos] + getMax(row - 1, pos, points);

            // once the recursive call is complete for the 1st element of
            // the 1st row, to keep a track of the maximum element, we store
            // it in a variable. Now we proceed to find the maximum point for
            // the 2nd element of the 1st row, using the same procedure of
            // seleting a SUITABLE elements.
            // 
            maxPoint = max(maxPoint, mx);
        }
    }

    // maxPoint contains the maximum point that can be scored after
    // considering all possible combination of paths in the given
    // matrix.
    return maxPoint;
}



int main()
{
    cout << "Enter the number of rows\n";
    int rows;
    cin >> rows;

    vector<vector<int>> points(rows, vector<int>(3));
    cout << "Enter the elements\n";

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < 3; j++)
            cin >> points[i][j];
    }

    int ans = getMax(rows - 1, -1, points);

    cout << "The maximum merit points is = " << ans << "\n";
    cout << "Total number of recursive calls = " << calls << "\n";
    return 0;
}