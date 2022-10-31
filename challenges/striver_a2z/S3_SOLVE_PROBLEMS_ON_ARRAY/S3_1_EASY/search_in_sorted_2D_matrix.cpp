#include <iostream>
#include <vector>
using namespace std;
int search_in_matrix(vector<vector<int>> &matrix, int key)
{
	int rows =  matrix.size();
	int cols = matrix[0].size();

	int low = 0;
	int high = rows * cols - 1;

	while(low <= high)
	{
		int mid = (low + high) / 2;
		if(matrix[mid / cols][mid % cols] == key)
			return true;

		if(matrix[mid / cols][mid % cols] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return false;
}


int main()
{
	int rows, cols;
	cout << "Enter the number of rows\n";
	cin >> rows;

	cout << "Enter the number of columns\n";
	cin >> cols;

	vector<vector<int>> v(rows, vector<int>(cols));

	cout << "Enter the elements in matrix\n";
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
			cin >> v[i][j];
	}

	int key;
	cout << "Enter the key\n";
	cin >> key;

	if(search_in_matrix(v, key))
		cout << "Element Found\n";
	else
		cout << "Element Not Found\n";
	return 0;
}