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

void insertAtPosition(stack<int> &st, int element) {
    if(st.empty()) {
        st.push(element);
        return;
    }
    if(st.top() <= element) {
        st.push(element);
        return;
    }

    int previousElement = st.top();
    st.pop();

    insertAtPosition(st, element);
    st.push(previousElement);
}

void sortStack(stack<int> &st) {
    if(st.empty())
        return;

    int previousElement = st.top();
    st.pop();

    sortStack(st);
    insertAtPosition(st, previousElement);
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

    sortStack(st);

    cout << "Stack after\n";
    printStack(st);

}