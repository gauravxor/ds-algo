/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10001 st prime number?
*/

#include <iostream>
using namespace std;
int main()
{
	int counter = 0;
	int x = 2;
	while (counter != 10001)
	{
        int flag = 0;
        for (int i = 2; (i * i) <= x;i++)
        {
            if(x%i==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cout << x << " ";
            counter++;
        }
        x++;
	}
    cout << "\n";
    cout << "Ans = " << x-1 << "\n";
    return 0;
}