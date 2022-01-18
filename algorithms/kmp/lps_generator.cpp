#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string str;
    cout << "Enter the string\n";
    cin >> str;

    // lps -> longest proper prefix which is also suffix
    
    int length = str.length();
    vector<int> lps(length,0);
    
    int maxCommon = 0;
    for(int pos = 1; pos < length; pos++)
    {
        if(str[pos] == str[maxCommon])
            lps[pos] = ++maxCommon;
        else
        {
            if(maxCommon == 0)
                lps[pos] = maxCommon;
            else
                maxCommon = lps[maxCommon - 1];
        }
    }
    cout << "The lps table is\n\n";
    for(int pos=0; pos<length; pos++)
        cout << str[pos] << " ";
    cout << "\n";

    for(auto it:lps)
        cout << it << " ";
    cout << "\n";
    return 0;
}   