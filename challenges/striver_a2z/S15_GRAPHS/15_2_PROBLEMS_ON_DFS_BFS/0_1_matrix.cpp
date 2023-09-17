#include <vector>
#include <iostream>
#include <queue>

using namespace std;

void solve(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    queue<pair<pair<int, int>, int>> q;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] == 1) {
                matrix[i][j] = -1;
                q.push({{i, j}, 0});
            }
        }
    }

    while(q.size() != 0) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int currentDistance = q.front().second;
        q.pop();

        vector<int> deltaRow = {-1, 0, 1, 0};
        vector<int> deltaCol = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++) {
            int newRow = row + deltaRow[i];
            int newCol = col + deltaCol[i];
            if(!(newRow >= 0 && newCol >= 0 && newRow < rows && newCol < cols)) {
                continue;
            }
            if(matrix[newRow][newCol] == 0) {
                matrix[newRow][newCol] = currentDistance + 1;
                q.push({{newRow, newCol}, currentDistance + 1});
            }
        }
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main () {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols, 0));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    solve(matrix);

    cout << "The updated matrix is \n";
    for(auto it : matrix) {
        for(int i : it) {
            cout << i << " ";
        }
        cout << "\n";
    }
}