#include <iostream>
#include <cstring>
using namespace std;

/** Reversing the string while */

string reverse(string str,int size)
{
    if(size < str.length())
        return reverse(str,size+1)+str[size];
    return "";
}

int main()
{
    string str;
    cout << "Enter the string\n";
    cin >> str;
    cout << "The original string is " << str << "\n";
    str = reverse(str,0);
    cout << "The reversed string is " << str << "\n";
    return 0;
}
