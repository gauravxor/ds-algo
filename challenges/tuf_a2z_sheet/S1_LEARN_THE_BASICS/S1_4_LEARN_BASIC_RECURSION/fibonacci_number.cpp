#include <iostream>
using namespace std;

int get_fibonacci(int n)
{
	if(n <= 1)
		return n;
	return get_fibonacci(n - 1) + get_fibonacci(n - 2);
}

int main()
{
	int n = 0;
	cout << "Enter the value of N\n";
	cin >> n;

	int term = get_fibonacci(n - 1);
	cout << "The Nth fibonacchi number is = " << term << "\n";
	return 0;
}