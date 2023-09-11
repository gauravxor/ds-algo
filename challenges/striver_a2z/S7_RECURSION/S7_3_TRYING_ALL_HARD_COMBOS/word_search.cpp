#include <iostream>
#include <vector>
using namespace std;

bool isPresent(int row, int col, int index, string target, vector<vector<char>> &v) {

    if (index == target.size()) {
        return true;
    }

    if (row < 0 || col < 0 || row == v.size() || col == v[0].size()) {
        return false;
    }

    if (v[row][col] != target[index]) {
        return false;
    }

    if (v[row][col] == '*') {
        return false;
    }

    char oldChar = v[row][col];
    v[row][col] = '*';
    bool res_1 = isPresent(row - 1, col, index + 1, target, v);
    bool res_2 = isPresent(row + 1, col, index + 1, target, v);
    bool res_3 = isPresent(row, col - 1, index + 1, target, v);
    bool res_4 = isPresent(row, col + 1, index + 1, target, v);
    v[row][col] = oldChar;
    return (res_1 || res_2 || res_3 || res_4);
}

bool solve(string target, vector<vector<char>> &v) {
    int row = v.size();
    int col = v[0].size();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (v[i][j] == target[0] && isPresent(i, j, 0, target, v)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int row, col;
    cin >> row >> col;

    vector<vector<char>> v(row, vector<char>(col));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> v[i][j];
        }
    }
    cout << "Enter the word to search\n";
    string target;
    cin >> target;
    bool result = solve(target, v);
    (result) ? cout << "Present\n" : cout << "Not Present\n";
    return 0;
}