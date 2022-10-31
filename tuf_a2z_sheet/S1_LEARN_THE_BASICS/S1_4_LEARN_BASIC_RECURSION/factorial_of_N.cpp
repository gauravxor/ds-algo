#include <iostream>
using namespace std;

int get_factorial(int number)
{
	if(number <= 0)
		return 1;

	return get_factorial(number - 1) * number;
}

int main()
{
	int number;
	cout << "Enter the number\n";
	cin >> number;

	int factorial = get_factorial(number);
	cout << "The factorial is = " << factorial << "\n";

	return 0;

}