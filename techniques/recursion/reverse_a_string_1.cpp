
/** Code just displays the string in revese order */

#include <iostream>
using namespace std;

void reverse(string str,int size)
{
    if(size<str.length())
        reverse(str,size+1);
    cout << str[size];
}
int main()
{
    cout << "Enter the string\n";
    string str;
    cin >> str;
    cout << "The original string is " << str << "\n";
    cout << "The reverse of the string is ";
    reverse(str,0);
    cout << "\n";

    return 0;
}
