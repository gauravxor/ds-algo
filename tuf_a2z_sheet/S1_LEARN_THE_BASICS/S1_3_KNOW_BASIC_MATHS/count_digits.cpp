/**
 * https://practice.geeksforgeeks.org/problems/count-digits5716/1
 */

#include <iostream>
using namespace std;

int count_digits(int number)
{
	int count = 0;
	while(number != 0)
	{
		number /= 10;
		count++;
	}
	return count;
}

int main()
{
	int number;
	cout << "Enter the number\n";
	cin >> number;

	int digits = count_digits(number);
	cout << "The number of digits is " << digits << "\n";
	return 0;
}
