#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

/* Brute force, bit manipulation technique using power set */

void generate(string str, vector<string> &ans) {
    int length = str.size();
    for(int i = 0; i < (1 << length); i++) {
        string s = "";
        for(int j = 0; j < length; j++) {
            if(i & (1 << j)) {
                s += str[j];
            }
        }
        if(s.size() > 0)
            ans.push_back(s);
    }
}


/* Recursive technique */

void generateSubsequence(string str, string newString, int index, vector<string> &ans) {
    if(index == str.length()) {
        ans.push_back(newString);
        return;
    }
    generateSubsequence(str, newString + str[index], index + 1, ans);
    generateSubsequence(str, newString, index + 1, ans);
}

int main () {
    string str;
    cin >> str;

    vector<string> ans;
    ans.push_back("");
    generateSubsequence(str, "", 0, ans);

    for(string s : ans)
        cout << s << " ";
    cout << "\n";
    return 0;
}