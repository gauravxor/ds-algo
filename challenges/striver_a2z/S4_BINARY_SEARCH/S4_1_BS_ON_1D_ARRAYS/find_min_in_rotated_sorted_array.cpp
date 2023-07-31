/* Given a rotated sorted array, find the minimum element */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/*  Find the point where rotation took place, compare it with the element at first index
    and return the minimum of them.
*/
int find_min_own(vector<int> &v) {
    int low = 0;
    int high = v.size() - 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(mid > 0 && v[mid] < v[mid - 1])
            return min(v[mid], v[0]);
        if(mid + 1 < v.size() && v[mid] > v[mid + 1])
            return min(v[mid + 1], v[0]);

        if(v[low] <= v[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return v[0];
}

/*  Find the sorted half and compare it's first element and store the minimum.
    Once that is done, eliminate the sorted half.
*/
int find_min(vector<int> &v) {
    int low = 0;
    int high = v.size() - 1;
    int ans = INT_MAX;
    while(low <= high) {
        int mid = (low + high) / 2;

        if(v[low] <= v[mid]) {
            ans = min(ans, v[low]);
            low = mid + 1;
        }
        else {
            ans = min(ans, v[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &it : v)
        cin >> it;

    cout << find_min_own(v) << "\n";
    // cout << find_min(v) << "\n";
    return 0;
}