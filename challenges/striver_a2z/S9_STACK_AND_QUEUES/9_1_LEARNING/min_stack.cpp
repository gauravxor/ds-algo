#include <stack>
#include <iostream>
#include <climits>

using namespace std;
class minStack {
    private:
        stack<int> st;
        int min;

    public:
        minStack () {
            min = 0;
        }

        void push(int data) {
            if(st.empty()) {
                st.push(data);
                min = data;
            }
            else {
                if(data < min) {
                    st.push(2 * data - min);
                    min = data;
                }
                else {
                    st.push(data);
                }
            }
        }

        void pop() {
            if(st.empty()) {
                cout << "Stack Empty\n";
                return;
            }

            if(st.top() < min) {
                min = 2 * min - st.top();
            }
            st.pop();
            if(st.empty()) {
                min = 0;
            }
        }

        int top() {
            if(st.empty()) {
                cout << "Stack Empty\n";
                return -1;
            }
            if(st.top() < min) {
                return min;
            }
            return st.top();
        }

        int getMin() {
            return min;
        }
};


int main() {
    int choice;
    minStack *st = new minStack();

    while(true) {
        cout << "1. to push\n";
        cout << "2. to pop\n";
        cout << "3. to get top\n";
        cout << "4. to get min\n";
        cin >> choice;

        switch(choice) {
            case 1:
                int data;
                cout << "Enter the data\n";
                cin >> data;
                st->push(data);
                break;

            case 2:
                st->pop();
                break;

            case 3:
                cout << st->top() << "\n";
                break;

            case 4:
                cout << st->getMin() << "\n";
                break;

            default:
                break;
        }
        cout << "\n";
    }
    return 0;
}