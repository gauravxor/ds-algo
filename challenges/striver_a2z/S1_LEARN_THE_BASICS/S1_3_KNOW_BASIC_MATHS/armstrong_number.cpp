#include <iostream>
#include <cmath>
using namespace std;

int check_armstrong(int number)
{
	int length = to_string(number).size();
	int sum = 0;
	int temp = number;

	while(temp != 0)
	{
		sum += (int)pow(temp % 10, length);
		temp /= 10;
	}

	return (number == sum);
}


int main()
{
	int number; 
	cout << "Enter the number\n";
	cin >> number;

	if(check_armstrong(number))
		cout << "Armstrong Number\n";
	else
		cout << "Not Armstrong\n";

	return 0;
}