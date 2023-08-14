#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void generateCombinations(vector<string> &letters, int index, string str, vector<string>& ans) {
    if(index == letters.size()) {
        return;
    }
    for(int i = 0; i < letters[index].size(); i++) {
        str += letters[index][i];
        generateCombinations(letters, index + 1, str, ans);
        if(str.size() == letters.size()) {
            ans.push_back(str);
        }
        str.pop_back();
    }
}

int main() {
    string digits;
    cin >> digits;

    vector<string> letters;
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    for(char digit : digits) {
        letters.push_back(mapping[digit - '0']);
    }

    vector<string> combinations;
    generateCombinations(letters, 0, "", combinations);

    cout << "The combinations are\n";
    for(string str : combinations) {
        cout << str << "\n";
    }
    return 0;
}
