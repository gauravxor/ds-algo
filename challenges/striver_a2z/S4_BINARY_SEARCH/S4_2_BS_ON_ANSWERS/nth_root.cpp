#include <iostream>

using namespace std;

int getProduct(int number, int power) {
    int product = 1;
    while(power--)
        product *= number;
    return product;
}

int getRoot(int m, int n) {
    int low = 0, high = m, mid;
    bool hasAns = false;
    while(low <= high) {
        mid = (low + high) / 2;
        int product = getProduct(mid, n);
        if(product == m) {
            hasAns = true;
            break;
        }

        if(product <= m) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    if(hasAns) return mid;
    else return -1;
}

int main () {
    int m, n;
    cin >> m >> n;

    int root = getRoot(m, n);
    cout << root << "\n";
    return 0;
}