#include <iostream>
#include <vector>

    using namespace std;

    int getRotations(vector<int> &v) {
        int low = 0, high = v.size() - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(v[low] <= v[mid]) {
                if(mid + 1 < v.size() && v[mid] > v[mid + 1])
                    return mid + 1;
                low = mid + 1;
            }
            else {
                if(mid - 1 >= 0 && v[mid - 1] > v[mid])
                    return mid;
                high = mid - 1;
            }
        }
        return 0;
    }

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &it : v)
        cin >> it;

    int rotations = getRotations(v);
    cout << "Rotations = " << rotations << "\n";
    return 0;
}