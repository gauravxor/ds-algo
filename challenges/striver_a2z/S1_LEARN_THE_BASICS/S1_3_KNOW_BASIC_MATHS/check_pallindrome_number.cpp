/**
 * https://leetcode.com/problems/palindrome-number/
 */

#include <iostream>
using namespace std;

int check_pallindrome(int number)
{
	string strNumber = to_string(number);
	int length = strNumber.size();

	for(int i = 0; i < length / 2; i++)
		if(strNumber[i] != strNumber[length - i - 1])
			return 0;
	return 1;
}

int main()
{
	cout << "Enter the number to be checked\n";
	int number;
	cin >> number;

	if(check_pallindrome(number))
		cout << "Pallindrome Number\n";
	else
		cout << "Not Pallindrome Number\n";

	return 0;
}