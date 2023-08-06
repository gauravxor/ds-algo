#include <iostream>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

void generateParenthesis(string str, int open, int close, vector<string> &validParenthesis) {
    if(open == 0 && close == 0) {
        validParenthesis.push_back(str);
        return;
    }

    if(open != 0) {
        generateParenthesis(str + '(', open - 1, close, validParenthesis);
    }

    /* We can remove close != 0 check, because open < close can handle that itself */
    if(close != 0 && open < close) {
        generateParenthesis(str + ')', open, close - 1, validParenthesis);
    }
}

int main () {
    int n;
    cin >> n;
    vector<string> validParenthesis;
    generateParenthesis("", n, n, validParenthesis);

    for(string str : validParenthesis) {
        cout << str << " ";
    }
    cout << "\n";
}