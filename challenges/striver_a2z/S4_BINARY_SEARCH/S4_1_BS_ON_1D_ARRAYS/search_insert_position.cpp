/* Given a sorted array and an element X, we need to find the position where X can be
   inserted so that the sorted order of the array is maintained. If that element is
   already present in the array, then that particular index is to be returned.

    Hint : We just need to find the lower_bound of the element to be inserted
*/


#include <iostream>
#include <vector>

using namespace std;

int lower_bound(vector<int> &v, int element) {

    /* If all elements are smaller than the insert element */
    if(v[v.size() - 1] < element)
        return v.size();

    int low = 0;
    int high = v.size() - 1;

    while(low < high) {
        int mid = (low + high) / 2;

        if(v[mid] < element) {
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
    int index = lower_bound(v, key);
    cout << "The insert index is = " << index << "\n";
    return 0;
}