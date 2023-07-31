/*  Given a sorted array, find the peak element.
    A peak element is one, that is greater than it's neighbours.
*/

#include <iostream>
#include <vector>

using namespace std;

int find_peak(vector<int> &v) {

    if(v.size() == 1) return 0;
    if(v[0] > v[1]) return 0;
    if(v[v.size() - 1] > v[v.size() - 2]) return v.size() - 1;

    int low = 1;
    int high = v.size() - 2;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(v[mid - 1] < v[mid] && v[mid] > v[mid + 1])
            return mid;

        if(v[mid - 1] < v[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &it : v)
        cin >> it;

    int peakElement = find_peak(v);
    cout << peakElement << "\n";
    return 0;
}