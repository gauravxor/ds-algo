#include <iostream>
#include <vector>
#include <set>

using namespace std;


void printMatrix(vector<vector<int>> &v)
{
    for(auto it: v)
    {
        for(auto n: it)
            cout << n << " ";
        cout << "\n";
    }
    cout << "\n";
}




void makeZero(vector<vector<int>> &v)
{
    int rows = v.size();
    int cols = v[0].size();

    bool firstCol = false;
    for(int i = 0; i < rows; i++)
    {
        if(v[i][0] == 0) 
            firstCol =  true;
        for(int j = 0; j < cols; j++)
        {
            if(v[i][j] == 0)
            {
                v[i][0] = 0;
                v[0][j] = 0;
            }       
        }
    }

    for(int i = rows - 1; i >= 0; i--)
    {
        for(int j = cols - 1; j >= 1; j--)
        {
            if(v[i][0] == 0 || v[0][j] == 0)
                v[i][j] = 0;
        }

        if(firstCol == true)
            v[i][0] = 0;
    }
}

int main()
{
    int rows, cols;
    cout << "Enter the no. of rows & cols\n";
    cin >> rows >> cols;

    vector<vector<int>> v(rows, vector<int>(cols));

    cout << "Enter the elements in DDA\n";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
            cin >> v[i][j];
    }


    cout << "The original matrix is\n";
    printMatrix(v);

    makeZero(v);

    cout << "The new matrix is\n";
    printMatrix(v);

    return 0;
}