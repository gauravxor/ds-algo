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



void printSpiralMatrix(vector<vector<int>> &v)
{
    int top = 0, bottom = v.size();
    int left = 0, right = v[0].size();

    while(top < bottom && left < right)
    {
        // left -> right
        for(int i = left; i < right; i++)
            cout << v[top][i] << " ";
        top++;

        // top -> bottom
        for(int i = top; i < bottom; i++)
            cout << v[i][right - 1] << " ";
        right--;


        // right -> left
        if(top < bottom)
        {
            for(int i = right - 1; i >= left; i--)
                cout << v[bottom - 1][i] << " ";
            bottom--;
        }

        // bottom -> up
        if(left < right)
        {
            for(int i = bottom - 1; i >= top; i--)
                cout << v[i][left] << " ";
            left++;
        }
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

    cout << "The spiral form of the matrix is\n";
    printSpiralMatrix(v);

    
    return 0;
}