#include <iostream>
using namespace std;

void print_n(int n)
{
	if(n == 0)
		return;

	cout << n << "\n";
	print_n(n - 1);
}

int main()
{
	int n;
	cout << "Enter the value of N\n";
	cin >> n;

	print_n(n);

	return 0;

}