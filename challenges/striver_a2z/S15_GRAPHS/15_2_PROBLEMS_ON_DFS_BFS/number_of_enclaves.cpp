#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfs(int row, int col, vector<vector<int>> &board) {
    int rows = board.size();
    int cols = board[0].size();
    vector<int> deltaRow = {-1, 0, 1, 0};
    vector<int> deltaCol = {0, 1, 0, -1};
    queue<pair<int, int>> q;
    q.push({row, col});
    board[row][col] = -1;
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int newRow = r + deltaRow[i];
            int newCol = c + deltaCol[i];
            if(newRow >= 0 && newCol >= 0 && newRow < rows && newCol < cols) {
                if(board[newRow][newCol] == 1) {
                    board[newRow][newCol] = -1;
                    q.push({newRow, newCol});
                }
            }
        }
    }
}

int solve(vector<vector<int>> &board) {
    int rows = board.size();
    int cols = board[0].size();

    /** Traversing the top and bottom rows */
    for(int i = 0; i < cols; i++) {
        if(board[0][i] == 1) {
            bfs(0, i, board);
        }
        if(board[rows - 1][i] == 1) {
            bfs(rows - 1, i, board);
        }
    }
    /** Traversing the left and right columns */
    for(int i = 0; i < rows; i++) {
        if(board[i][cols - 1] == 1) {
            bfs(i, cols - 1, board);
        }
        if(board[i][0] == 1) {
            bfs(i, 0, board);
        }
    }
    int enclaves = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(board[i][j] == 1) {
                enclaves++;
            }
        }
    }
    return enclaves;
}

int main () {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> board(rows, vector<int> (cols));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> board[i][j];
        }
    }
    int enclaves = solve(board);
    cout << "The new board is\n";
    for(auto it : board) {
        for(int i : it) {
            cout << i << " ";
        }
        cout << "\n";
    }
    cout << "Number of enclaves = " << enclaves << "\n";
    return 0;
}