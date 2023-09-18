#include <vector>
#include <iostream>
#include <set>
#include <queue>

using namespace std;

int getLength(string beginWord, string endWord, vector<string> &wordList) {
    set<string> st(wordList.begin(), wordList.end());
    if(st.find(endWord) == st.end()) {
        return 0;
    }
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    if(st.find(beginWord) != st.end()) {
        st.erase(st.find(beginWord));
    }
    while(!q.empty()) {
        string str = q.front().first;
        int length = q.front().second;
        q.pop();
        if(str == endWord) {
            return length;
        }
        for(int i = 0; i < str.size(); i++) {
            string nstr = str;
            for(char j = 'a'; j <= 'z'; j++) {
                nstr[i] = j;
                if(nstr != str && st.find(nstr) != st.end()) {
                    q.push({nstr, length + 1});
                    st.erase(st.find(nstr));
                }
            }
        }
    }
    return 0;
}

int main () {
    int n;
    cin >> n;
    vector<string> list(n);
    for(auto &it : list) {
        cin >> it;
    }
    string beginWord, endWord;
    cin >> beginWord >> endWord;
    int length = getLength(beginWord, endWord, list);
    cout << "Length = " << length << "\n";
    return 0;
}