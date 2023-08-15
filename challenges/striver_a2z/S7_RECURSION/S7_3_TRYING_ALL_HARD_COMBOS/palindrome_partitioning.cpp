#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool isPalindrome(string str) {
    int start = 0, end = str.size() - 1;
    while(start <= end) {
        if(str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void makePartition(string str, int index, vector<string> temp, vector<vector<string>> &ans) {
    if(index == str.size()) {
        ans.push_back(temp);
        return;
    }
    for(int i = index; i < str.size(); ++i) {
        string currentString = str.substr(index, i - index + 1);
        if(isPalindrome(currentString) == true) {
            temp.push_back(currentString);
            makePartition(str, i + 1, temp, ans);
            temp.pop_back();
        }
    }
}

int main() {
    string str;
    cin >> str;
    vector<vector<string>> ans;
    makePartition(str, 0, {}, ans);

    cout << "Possible Palindrome Partitions are\n";
    for(auto it : ans) {
        for(string s : it) {
            cout << s << " | ";
        }
        cout << "\n";
    }
}