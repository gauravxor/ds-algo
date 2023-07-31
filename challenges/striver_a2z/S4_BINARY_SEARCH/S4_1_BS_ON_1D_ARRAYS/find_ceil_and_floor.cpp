/*  Given an array and an element X. Find the ceil and floor of the element X

    Ceil : Largest element that is >= X (lower_bound)
    Floor : Smallest element that is <= X

    Hint : Floor of X will be the element behind Ceil or the same element.
*/

#include <iostream>
#include <vector>

using namespace std;

int find_ceil(vector<int> &v, int element) {

    /* If all elements are smaller than the target*/
    if(v[v.size() - 1] < element)
        return -1;

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

    int element;
    cin >> element;
    int ceil = find_ceil(v, element), floor = 0;

    if(ceil == -1)
        floor = v.size() - 1;
    else
    if(v[ceil] == element)
        floor = ceil;
    else
        floor = (ceil > 0) ? ceil - 1 : -1;

    cout << "Floor = " << floor << " " << "Ceil = " << ceil << "\n";
    return 0;
}