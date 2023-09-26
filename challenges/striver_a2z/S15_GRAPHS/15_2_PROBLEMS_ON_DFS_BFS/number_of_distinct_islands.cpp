#include <iostream>
#include <set>
#include <vector>
using namespace std;

void dfs(int r, int c, int src_r, int src_c, vector<pair<int, int>> &temp, vector<vector<bool>> &vis,
         vector<vector<int>> &matrix) {

    temp.push_back({r - src_r, c - src_c});
    vis[r][c] = true;
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> deltaRow = {0, 1, 0, -1};
    vector<int> deltaCol = {1, 0, -1, 0};

    for (int i = 0; i < 4; i++) {
        int nr = r + deltaRow[i];
        int nc = c + deltaCol[i];
        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !vis[nr][nc] && matrix[nr][nc] == 1) {
            dfs(nr, nc, src_r, src_c, temp, vis, matrix);
        }
    }
}

int getCount(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<bool>> vis(rows, vector<bool>(cols, false));
    set<vector<pair<int, int>>> st;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (vis[i][j] == false && matrix[i][j] == 1) {
                vector<pair<int, int>> temp;
                dfs(i, j, i, j, temp, vis, matrix);
                st.insert(temp);
            }
        }
    }
    return st.size();
}

int main() {
    int row, col;
    cin >> row >> col;

    vector<vector<int>> matrix(row, vector<int>(col));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> matrix[i][j];
        }
    }

    int islands = getCount(matrix);
    cout << "Distinct Islands = " << islands << "\n";
    return 0;
}