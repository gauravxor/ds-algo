#include <iostream>
#include <vector>

using namespace std;

void generate(int openCount, int closeCount, string temp, vector<string> &ans) {
    if(openCount == 0 && closeCount == 0) {
        ans.push_back(temp);
        return;
    }

    if(openCount != 0) {
        generate(openCount - 1, closeCount, temp + "(", ans);
    }
    if(closeCount > openCount) {
        generate(openCount, closeCount - 1, temp + ")", ans);
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> ans;

    generate(n, n, "", ans);

    cout << "Valid parenthesis are\n";
    for(string str : ans) {
        cout << str << "\n";
    }
    return 0;
}