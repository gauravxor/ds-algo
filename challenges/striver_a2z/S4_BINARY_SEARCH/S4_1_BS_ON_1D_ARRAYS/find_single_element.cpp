/*  Given an sorted array where every elements appears twice, except one element,
    Find that element.
*/

#include <iostream>
#include <vector>

using namespace std;

int find_single(vector<int> &v) {

    int low = 0;
    int high = v.size() - 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(mid > 0 && v[mid] == v[mid - 1]) {
            int distance = mid - low + 1;
            if(distance % 2 == 0)
                low = mid + 2;
            else
                high = mid - 2;
        }
        else
        if(mid + 1 < v.size() && v[mid] == v[mid + 1]) {
            int distance = high - mid + 1;
            if(distance % 2 == 0)
                high = mid - 1;
            else
                low = mid + 2;
        }
        else
            return v[mid];
    }
    return v[low];
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &it : v)
        cin >> it;
    cout << find_single(v) << "\n";
    return 0;
}