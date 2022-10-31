#include <iostream>
using namespace std;

void print_something(string str, int times)
{
	if(times == 0)
		return;

	cout << str << "\n";
	print_something(str, times - 1);
}

int main()
{
	int times = 0;
	cout << "How many times you wanna print SOMETHING\n";
	cin >> times;

	string str = "SOMETHING";
	print_something(str, times);

	return 0;

}