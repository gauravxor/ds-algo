/** 
 * Given a N x N matrix, rotate it by 90 degrees in
 * clockwise manner.
 * 
 * 
 * Algorithm :
 * TC : O(n * n) + O(n * n) | SC : O(1)
 * -------------------------------------
 * 
 * Reverse the ROWS (last row becomes the first row)
 * and after reversing, swap the non diagonal 
 * elements with their opposite index.
 *
 **/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<vector<int>> &matrix, int row, int col)
{
	reverse(matrix.begin(), matrix.end());
	for(int i = 0; i < row; i++)
	{
		for(int j = i; j < col; j++)
			swap(matrix[i][j], matrix[j][i]);			
	}	
}


int main()
{
	int row, col;
	cout << "Enter the number of rows and columns\n";
	cin >> row >> col;

	vector<vector<int>> matrix;

	cout << "Enter the elements in matrix\n";
	for(int i = 0; i < row; i++)
	{
		vector<int> rows(col);
		for(int j = 0; j < col; j++)
			cin >> rows[j];

		matrix.push_back(rows);
	}

	cout << "The matrix is\n";
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
			cout << matrix[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";


	rotate(matrix, row, col);

	cout << "The matrix after rotation\n";
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
			cout << matrix[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
	return 0;
}