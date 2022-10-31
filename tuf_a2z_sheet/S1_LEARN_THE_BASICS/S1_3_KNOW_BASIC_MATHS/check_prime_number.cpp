#include <iostream>
#include <cmath>
using namespace std;


int check_prime(int number)
{
	int count = 0;
	for(int i = 1; i <= number; i++)
		if(number % i == 0)
			count++;
	return (count == 2);
}


// sqaure root is the dividing point of all divisors
int check_prime_opt(int number)
{
	int count = 0;

	for(int i = 2; i <= sqrt(number); i++)
		if(number % i == 0)
			count++;

	return (count == 0 && number != 1);
}


int main()
{
	cout << "Enter the number\n";
	int number;
	cin >> number;

	// int result = check_prime(number);
	int result = check_prime_opt(number);

	if(result)
		cout << "Prime Number\n";
	else
		cout << "Not Prime\n";
	return 0;
}