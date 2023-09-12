#include <iostream>
#include <vector>
using namespace std;

void dfs(int row, vector<vector<int>> &matrix, vector<bool> &visited) {
    visited[row] = true;
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[row][i] == 1 && visited[i] == false) {
            dfs(i, matrix, visited);
        }
    }
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int count = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            count++;
            dfs(i, matrix, visited);
        }
    }
    cout << "Provinces = " << count << "\n";
    return 0;
}