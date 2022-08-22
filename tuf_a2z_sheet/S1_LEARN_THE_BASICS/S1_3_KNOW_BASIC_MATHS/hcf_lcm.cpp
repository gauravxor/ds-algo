#include <iostream>
using namespace std;


long long getHcf(long long first, long long second)
{
	while(first % second != 0)
	{
		long long temp = first;
		first = second;
		second = temp % second;
	}	
	return second;
}


int main()
{
	long long first, second;
	cout << "Enter the first number\n";
	cin >> first;

	cout << "Enter the second number\n";
	cin >> second;

	if(first < second)
		swap(first, second);

	long long hcf = getHcf(first, second);
	
	// we divide the larger of the two numbers by hcf to prevent overflows	
	long long lcm = (max(first, second) / hcf ) * min(first, second);

	cout << "HCF = " << hcf << "\n";
	cout << "LCM = " << lcm << "\n";
	
	return 0;
}