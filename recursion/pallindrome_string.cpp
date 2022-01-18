#include <iostream>
using namespace std;

int checker(string str,int size)
{
    if(size < str.length()/2)
        checker(str,size+1);
    if(str[size] == str[])

}

int main()
{
    string str;
    cout << "Enter the string\n";
    cin >> str;
    if(checker(str,0))
        cout << "Pallindrome\n";
    else
        cout << "Not Pallindrome\n";
    return 0;
}