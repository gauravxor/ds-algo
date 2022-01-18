#include <iostream>
#include <vector>
using namespace std;

// TC : O(n) | SC : O(n) (stack space)
int f(int num)
{
    if(num <= 1)
        return 1;
    return num * f(num - 1);
}


int main()
{
    int num;
    cout << "Enter the number\n";
    cin >> num;
    int fact = f(num);
    cout << "The factorial is = " << fact << "\n";
    return 0;
}
