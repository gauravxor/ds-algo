/*  Given a sorted array and an element X, we need to find the first and last occurence
    of the element X.

    Hint : We just need to find the upper and lower bound of X
*/


#include <iostream>
#include <vector>

using namespace std;

int lower_bound(vector<int> &v, int element) {

    /* If all elements are smaller than the search element */
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

int upper_bound(vector<int> &v, int element) {

    /* If all elements are smaller than or equal to the search element */
    if(v[v.size() - 1] <= element)
        return v.size();

    int low = 0;
    int high = v.size() - 1;

    while(low < high) {
        int mid = (low + high) / 2;

        if(v[mid] <= element) {
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

    int lb = lower_bound(v, key);
    int ub = upper_bound(v, key);

    if(lb == v.size() || v[lb] != key)
        cout << "Start = -1 End = -1\n";
    else
        cout << "Start = " << lb << " End = " << ub - 1<< "\n";
    return 0;
}