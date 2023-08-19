#include <iostream>
#include <vector>

using namespace std;

void generate(int n, vector<bool> &primes) {
    for(int i = 2; i * i <= n; i++) {
        for(int j = i * 2; j <= n; j += i) {
            primes[j] = false;
        }
    }
}
int main () {
    int n;
    cin >> n;
    vector<bool> primes(n + 1, true);
    generate(n, primes);

    for(int i = 2; i <= n; i++) {
        if(primes[i] == true) {
            cout << i << "\n";
        }
    }
    return 0;
}