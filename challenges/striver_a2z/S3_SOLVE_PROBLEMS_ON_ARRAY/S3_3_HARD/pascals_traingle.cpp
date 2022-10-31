#include <iostream>
#include <vector>
using namespace std;



vector<vector<int>> generateTraingle(int n)
{
    vector<vector<int>> triangle(n);
    for(int i = 0; i < n; i++)
    {
        triangle[i].resize(i + 1);
        triangle[i][0] = triangle[i][i] = 1;

        for(int j = 1; j < i; j++)
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
    }
    return triangle;
}

int main()
{
    cout << "Enter the size of the triangle\n";
    int n;
    cin >> n;

    vector<vector<int>> traingle = generateTraingle(n);

    cout << "The generated traingle is\n";
    for(int i = 0; i < traingle.size(); i++)
    {
        for(int j = 0; j < traingle[i].size(); j++)
            cout << traingle[i][j] << " ";
        cout << "\n";
    }

    return 0;
}