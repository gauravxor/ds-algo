/**
 * Memoized version of ninja training problem
 */

#include <iostream>
#include <climits>
#include <vector>

using namespace std;
unsigned long long int calls = 0;


int getMax(int rows, int lastPos, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    calls++;
    // check if the solution of the subproblem already exists.
    // If it exists, then we can directly return the value.
    if(dp[rows][lastPos] != -1) return dp[rows][lastPos];

    // checking for the base condition, i.e. if the we are at the
    // lowest level of the row. (here the lowest level is the
    // first row i.e. 0th index)
    
    if(rows == 0)
    {
        int maxPoint = 0;
        for(int pos = 0; pos < 3; pos++)
        {
            // checking that if the last selected position is not adjacent 
            // to the current position. If it doesnt coincide, then it is a 
            // SUITABLE  position to be taken into consideration.
            if(pos != lastPos)
                maxPoint = max(maxPoint, points[0][pos]);
        }

        // after we have found the solution for the a particular index,
        // we store the value in the DP grid.
        
        return (dp[rows][lastPos] = maxPoint);
    }


    // the main body of the recursive code, just starts from the bottom right corner
    // of the grid and taking that element, it moves upward and calculates the maximum
    // point it can achieve if that particular point is taken into consideration.
    
    int maxPoints = 0;

    for(int pos = 0; pos < 3; pos++)
    {
        if(pos != lastPos)
        {
            int currentMax = points[rows][pos] + getMax(rows - 1, pos, points, dp);
            maxPoints = max(maxPoints, currentMax);
        }
    }
    return (dp[rows][lastPos] = maxPoints);
}
int main()
{
    cout << "Enter the number of rows\n";
    int rows;
    cin >> rows;

    vector<vector<int>> points(rows, vector<int> (3));

    cout << "Enter the elements of the matrix\n";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < 3; j++)
            cin >> points[i][j];
    }

    int lastPos = 3;
    vector<vector<int>> dp(rows, vector<int>(4, -1));
    int answer = getMax(rows - 1, lastPos, points, dp);

    cout << "The maximum points that can be achieved = " << answer << "\n";
    cout << "Total number of recursive calls = " << calls << "\n";

    cout << "\nThe genrerated DP grid is\n";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < 4; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }

    return 0;
}