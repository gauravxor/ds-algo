#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> generate(vector<int> &v) {
    stack<int> st;
    vector<int> nge(v.size());
    for(int i = v.size() - 1; i >= 0; i--) {
        while(!st.empty() && st.top() <= v[i]) {
            st.pop();
        }
        nge[i] = st.empty() ? -1 : st.top();
        st.push(v[i]);
    }
    return nge;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &it : v) {
        cin >> it;
    }

    vector<int> nge = generate(v);

    for(int i : nge) {
        cout << i << " ";
    }
    cout << "\n";
}