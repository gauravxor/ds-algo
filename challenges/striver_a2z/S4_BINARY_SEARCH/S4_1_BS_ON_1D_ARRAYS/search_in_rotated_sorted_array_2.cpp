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

        if(target == v[mid])
            return mid;

        /*
            If all three elements becomes equal then we cannot determine which half is sorted
            So we move the pointers accordingly till the three elements become different.
        */
        if(v[low] == v[mid] && v[mid] == v[high]) {
            low++;
            high--;
            continue;
        }

        if(v[low] <= v[mid]) {
            if(target >= v[low] && target <= v[mid])
                high = mid;
            else
                low = mid + 1;
        }
        else {
            if(target >= v[mid] && target <= v[high])
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