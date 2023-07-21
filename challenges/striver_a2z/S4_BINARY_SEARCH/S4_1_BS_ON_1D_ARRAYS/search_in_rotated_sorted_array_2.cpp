#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &v, int target) {
    int low = 0, high = v.size() - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(target == v[mid])
            return true;

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
            if(target >= v[mid + 1] && target <= v[high])
                low = mid;
            else
                high = mid - 1;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &it: v)
        cin >> it;

    int target;
    cin >> target;

    int isPresent = search(v, target);
    (isPresent) ? cout << "Found\n" : cout << "Not Found\n";
    return 0;
}