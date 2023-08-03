#include <iostream>

using namespace std;


int getRoot(int n) {
    int low = 0;
    int high = n;

    while(low <= high) {
        int mid = (low + high) / 2;
        int product = mid * mid;
        if(product == n)
            return mid;

        if(product <= n) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return high;
}

int main () {
    int n;
    cin >> n;

    int root = getRoot(n);
    cout << root << "\n";
    return 0;
}