/**
 * https://leetcode.com/problems/reverse-integer/
 */


#include <iostream>
using namespace std;

int reverse_number(int number)
{
	int reversed_number = 0;
	while(number != 0)
	{
		int digit = number % 10;
		reversed_number = reversed_number * 10 + digit;
		number /= 10;
	}
	return reversed_number;
}


int main()
{
	cout << "Enter the number\n";
	int number;
	cin >> number;

	int reversed_number = reverse_number(number);
	cout << "The reversed number is " << reversed_number << "\n";
	return 0;

}