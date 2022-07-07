#include <iostream>
using namespace std;


int reverse(int num)
{
    // can also use global variables
    static int newNumber = 0;
    if(num != 0)
    {
        newNumber = newNumber*10 + (num%10);
        reverse(num/10);
    }
    return newNumber;
}


int main()
{
    cout << "Enter the number to be checked\n";
    int num;
    cin >> num;
    int revNum = reverse(num);
    if(revNum == num)
        cout << "Pallindrome Number\n";
    else
        cout << "Not Pallindrome Number\n";
    return 0;
}