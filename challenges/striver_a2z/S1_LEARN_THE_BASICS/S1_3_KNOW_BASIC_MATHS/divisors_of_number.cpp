/**
 * https://practice.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1
 */
#include <iostream>
#include <cmath>
using namespace std;

// TC : O(n) | SC : O(1)
void print_divisors(int number)
{
	cout << "The divisors of " << number << " are \n";
	for(int i = 1; i <= number; i++)
		if(number % i == 0)
			cout << i << " ";
	cout << "\n";
}


// TC : O(sqrt(n)) | SC : O(1)
void print_divisors_opt(int number)
{
	int endPoint = sqrt(number);
	for(int i = 1; i <= endPoint; i++)
	{
		if(number % i == 0)
		{
			cout << i << " ";
			if(i != number / i)
				cout << number / i << " ";
		}
	}
	cout << "\n";
}

int main()
{
	int number;
	cout << "Enter the number\n";
	cin >> number;

	// optimised version
	print_divisors_opt(number);

	// print_divisors(number);
	return 0;
}