
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElement(vector<int>& v) {
    stack<int> stack;
    vector<int> result(v.size(), -1);

    for(int i = 0; i < v.size(); i++) {
        while(!stack.empty() && v[i] < v[stack.top()]) {
            result[stack.top()] = v[i];
            stack.pop();
        }
        stack.push(i);
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &it : v) {
        cin >> it;
    }

    vector<int> nse = nextSmallerElement(v);

    for(int i : nse) {
        cout << i << " ";
    }
    cout << "\n";
}