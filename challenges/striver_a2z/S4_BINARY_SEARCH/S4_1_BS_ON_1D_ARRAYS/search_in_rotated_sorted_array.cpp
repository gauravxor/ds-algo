/*  Given a rotated sorted array and an element X. Find if X is present in the array

    Hint :  Check for sorted segments and perform the search there if the X lies there,
            or else perform the search in other unsorted sergment.
*/

#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &v, int target) {
    int low = 0;
    int high = v.size() - 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(v[mid] == target)
            return mid;

        if(v[low] <= v[mid]) {
            if(v[low] <= target && target <= v[mid])
                high = mid;
            else
                low = mid + 1;
        }
        else {
            if(v[mid] <= target && target <= v[high])
                low = mid;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &it: v)
        cin >> it;

    int target;
    cin >> target;

    int index = search(v, target);
    cout << index << "\n";

    return 0;
}