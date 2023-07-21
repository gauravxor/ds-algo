#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int getMinimum(vector<int> &v) {
    int low = 0, high = v.size() - 1;
    int minimum = INT_MAX;

    while(low <= high) {
        int mid = (low + high) / 2;

        /* Check if left half is sorted */
        if(v[low] <= v[mid]) {
            minimum = min(minimum, v[low]);
            low = mid + 1;
        }
        else {
            minimum = min(minimum, min(v[mid], v[mid + 1]));
            high = mid - 1;
        }
    }
    return minimum;

}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &it: v)
        cin >> it;

    int minimum = getMinimum(v);
    cout << "The minimum element is = " << minimum << "\n";
    return 0;
}