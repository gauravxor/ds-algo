/** Number of undirected graph with non connected components */
#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    int result = 1 << ((n * (n - 1)) / 2);
    cout << result << "\n";
    return 0;
}