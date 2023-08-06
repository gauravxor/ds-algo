#include <stack>
#include <iostream>

using namespace std;

void printStack(stack<int> st) {
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
}

void insertAtBottom(stack<int> &st, int element) {
    if(st.empty()) {
        st.push(element);
        return;
    }

    int previousElement = st.top();
    st.pop();

    insertAtBottom(st, element);
    st.push(previousElement);
}

void reverseStack(stack<int> &st) {
    if(st.empty())
        return;

    int previousElement = st.top();
    st.pop();

    reverseStack(st);
    insertAtBottom(st, previousElement);
}

int main () {
    int n, x;
    cin >> n;
    stack<int> st;
    for(int i = 0; i < n; i++) {
        cin >> x;
        st.push(x);
    }

    cout << "Stack before\n";
    printStack(st);

    reverseStack(st);

    cout << "Stack after\n";
    printStack(st);

}