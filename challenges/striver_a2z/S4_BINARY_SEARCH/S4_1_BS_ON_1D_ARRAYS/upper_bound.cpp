/* Y is upper bound of X, means Y is a number such that [Y > X] */

#include <iostream>
#include <vector>

using namespace std;

int upper_bound(vector<int> &v, int target) {

    /* If all elements are smaller than the target*/
    if(v[v.size() - 1] <= target)
        return -1;

    int low = 0;
    int high = v.size() - 1;

    while(low < high) {
        int mid = (low + high) / 2;

        if(v[mid] <= target) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    return high;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &it : v)
        cin >> it;

    int key;
    cin >> key;
    cout << upper_bound(v, key) << "\n";
    return 0;
}