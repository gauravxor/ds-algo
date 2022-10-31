#include <iostream>
using namespace std;

void print_name(string name, int times)
{
	if(times == 0)
		return;

	cout << name << "\n";
	print_something(name, times - 1);
}

int main()
{
	int times = 0;
	string name;
	
	cout << "Enter the name\n";
	cin >> name;

	cout << "How many times you wanna print the NAME?\n";
	cin >> times;


	print_name(name, times);

	return 0;

}