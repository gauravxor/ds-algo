#include <iostream>
using namespace std;

void print_n(int n)
{
	if(n == 0)
		return;

	print_n(n - 1);
	cout << n << "\n";
}

int main()
{
	int n;
	cout << "Enter the value of N\n";
	cin >> n;

	print_n(n);

	return 0;

}