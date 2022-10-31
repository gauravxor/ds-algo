#include <iostream>
using namespace std;

int get_sum(int n)
{
	if(n == 0)
		return 0;
	return get_sum(n - 1) + n;
}

int main()
{
	int n;
	cout << "Enter the value of N\n";
	cin >> n;

	int sum = get_sum(n);
	cout << "The sum is = " << sum << "\n";

	return 0;

}