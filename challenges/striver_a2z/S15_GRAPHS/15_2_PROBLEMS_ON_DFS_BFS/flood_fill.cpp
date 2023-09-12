#include <vector>
#include <iostream>

using namespace std;

void floodFill(int r, int c, int oldColor, int newColor, vector<vector<int>> &mat, vector<vector<int>> &res) {
    if(r < 0 || r >= mat.size() || c < 0 || c >= mat[0].size()) {
        return;
    }
    if(mat[r][c] != oldColor || res[r][c] == newColor) {
        return;
    }
    res[r][c] = newColor;
    floodFill(r, c - 1, oldColor, newColor, mat, res);
    floodFill(r, c + 1, oldColor, newColor, mat, res);
    floodFill(r - 1, c, oldColor, newColor, mat, res);
    floodFill(r + 1, c, oldColor, newColor, mat, res);
}


int main () {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> matrix(rows, vector<int> (cols));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    int sourceRow, sourceCol, newColor;
    cin >> sourceRow >> sourceCol >> newColor;

    vector<vector<int>> resMatrix = matrix;

    int oldColor = matrix[sourceRow][sourceCol];

    floodFill(sourceRow, sourceCol, oldColor, newColor, matrix, resMatrix);

    cout << "The new image is\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
           cout << resMatrix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}