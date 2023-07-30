#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> &v, int key) {
    int low = 0;
    int high = v.size() - 1;
    while(low <= high) {
        int mid = high - (high - low) / 2;
        if(v[mid] == key)
            return mid;

        if(v[mid] < key)
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

    int key;
    cin >> key;

    int index = binary_search(v, key);
    cout << index << "\n";
    return 0;
}