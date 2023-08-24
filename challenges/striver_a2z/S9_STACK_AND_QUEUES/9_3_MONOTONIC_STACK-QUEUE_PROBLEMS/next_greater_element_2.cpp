/* This time we have a circular array */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int>& v) {
    vector<int> result(v.size(), -1);
    stack<int> stack;

    for (int i = 0; i < 2 * v.size(); ++i) {
        int curr = v[i % v.size()];

        while (!stack.empty() && curr > v[stack.top()]) {
            result[stack.top()] = curr;
            stack.pop();
        }

        // making sure that we are not recalculating.
        if (i < v.size()) {
            stack.push(i);
        }
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

    vector<int> nge = nextGreaterElement(v);

    for(int i : nge) {
        cout << i << " ";
    }
    cout << "\n";
}