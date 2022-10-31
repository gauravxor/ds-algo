#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



void rotate(vector<vector<int>> &v)
{
    int rows = v.size();

    // transposing
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < i; j++)
            swap(v[i][j], v[j][i]);
    

    // reversing individual rows
    for(int i = 0; i < rows; i++)
        reverse(v[i].begin(), v[i].end());
}


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

    rotate(v);

    cout << "The rotated matrix is\n";
    printMatrix(v);
}