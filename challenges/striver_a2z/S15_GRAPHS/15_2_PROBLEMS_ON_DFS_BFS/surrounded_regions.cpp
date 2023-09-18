#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfs(int row, int col, vector<vector<char>> &board) {
    int rows = board.size();
    int cols = board[0].size();
    vector<int> deltaRow = {-1, 0, 1, 0};
    vector<int> deltaCol = {0, 1, 0, -1};
    queue<pair<int, int>> q;
    q.push({row, col});
    board[row][col] = 'V';
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int newRow = r + deltaRow[i];
            int newCol = c + deltaCol[i];
            if(newRow >= 0 && newCol >= 0 && newRow < rows && newCol < cols) {
                if(board[newRow][newCol] == 'O') {
                    board[newRow][newCol] = 'V';
                    q.push({newRow, newCol});

                }
            }
        }
    }
}

void solve(vector<vector<char>> &board) {
    int rows = board.size();
    int cols = board[0].size();

    /** Traversing the top and bottom rows */
    for(int i = 0; i < cols; i++) {
        if(board[0][i] == 'O') {
            bfs(0, i, board);
        }
        if(board[rows - 1][i] == 'O') {
            bfs(rows - 1, i, board);
        }
    }
    /** Traversing the left and right columns */
    for(int i = 0; i < rows; i++) {
        if(board[i][cols - 1] == 'O') {
            bfs(i, cols - 1, board);
        }
        if(board[i][0] == 'O') {
            bfs(i, 0, board);
        }
    }
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            board[i][j] = (board[i][j] == 'V') ? 'O' : 'X';
        }
    }
}

int main () {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<char>> board(rows, vector<char> (cols));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> board[i][j];
        }
    }
    solve(board);
    cout << "The new board is\n";
    for(auto it : board) {
        for(char i : it) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}