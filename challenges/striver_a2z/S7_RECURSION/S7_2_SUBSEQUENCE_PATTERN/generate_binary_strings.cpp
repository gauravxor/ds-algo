#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/** These two functions are for brute force recursive solution

bool isValid(string str, int n) {
    for(int i = 0; i < n - 1; i++) {
        if(str[i] == str[i + 1] && str[i] == '1')
            return false;
    }
    return true;
}

void generateStrings(string str, int n, vector<string> &binStrings) {
    if(str.size() > n)
        return;

    generateStrings(str + '0', n, binStrings);
    generateStrings(str + '1', n, binStrings);

    if(str.size() == n && isValid(str, n))
        binStrings.push_back(str);
}

**/


void generateStrings(string str, int currentIndex, int size, vector<string> &binaryStrings) {
    if(currentIndex == size) {
        binaryStrings.push_back(str);
        return ;
    }

    generateStrings(str + '0', currentIndex + 1, size, binaryStrings);
    if(currentIndex == 0 || str[currentIndex - 1] == '0') {
        generateStrings(str + '1', currentIndex + 1, size, binaryStrings);
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> binStrings;
    generateStrings("", 0, n, binStrings);

    for(string str : binStrings)
        cout << str << " ";
    cout << "\n";
    return 0;
}