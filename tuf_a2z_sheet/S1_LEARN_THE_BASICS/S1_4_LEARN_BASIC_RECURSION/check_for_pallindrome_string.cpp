#include <iostream>
using namespace std;

int check_pallindrome(string str, int leftIndex, int rightIndex)
{
	if(leftIndex > rightIndex)
		return 1;

	if(str[leftIndex] != str[rightIndex])
		return 0;

	return check_pallindrome(str, leftIndex + 1, rightIndex - 1);
}

int main()
{
	string str;
	cout << "Enter the string\n";
	cin >> str;

	if(check_pallindrome(str, 0, str.size() - 1))
		cout << "Pallindrome String\n";
	else
		cout << "Not a Pallindrome String\n";

	return 0;
}