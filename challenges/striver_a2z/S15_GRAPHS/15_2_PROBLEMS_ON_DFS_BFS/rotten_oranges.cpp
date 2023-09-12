#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int getMinTime(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // {{row, col}, time}
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> visited(rows, vector<int>(cols));

    // filling the queue with rotten oranges & setting up visited matrix
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] == 2) {
                q.push({{i, j}, 0});
                visited[i][j] = 2;
            }
        }
    }

    int time = 0;
    vector<int> deltaRow = {-1, 0, 1, 0}, deltaCol = {0, 1, 0, -1};

    while(q.empty() == false) {
        int currentRow = q.front().first.first;
        int currentCol = q.front().first.second;
        int currentTime = q.front().second;
        q.pop();
        time = max(time, currentTime);

        for(int i = 0; i < 4; i++) {
            int newRow = currentRow + deltaRow[i];
            int newCol = currentCol + deltaCol[i];
            if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                if(matrix[newRow][newCol] == 1 && visited[newRow][newCol] == 0) {
                    q.push({{newRow, newCol}, currentTime + 1});
                    visited[newRow][newCol] = 2;
                }
            }
        }
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] == 1 && visited[i][j] == 0) {
                return -1;
            }
        }
    }
    return time;
}

int main () {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> matrix(rows, vector<int>(cols));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    int minTime = getMinTime(matrix);
    cout << "Minimum Time = " << minTime << "\n";
    return 0;
}