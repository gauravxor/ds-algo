#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getAllocation(vector<int> &v, int distanceAllowed) {
    int cowsAllocated = 1;
    int previousStallIndex = 0;
    for(int i = 1; i < v.size(); i++) {
        if((v[i] - v[previousStallIndex]) >= distanceAllowed) {
            cowsAllocated += 1;
            previousStallIndex = i;
        }
    }
    return cowsAllocated;
}

int solve(vector<int> &v, int cows) {
    sort(v.begin(), v.end());

    /** If all cows are ajacent, then smallest distance will be 1*/
    int low = 1;

    /** If both cows are at the edges, then distance between them will be largest */
    int high = v.back() - v[0];

    /** To store the answer. The default value is set to max*/
    int minDistance = high;

    while(low <= high) {
        int mid = (low + high) / 2;

        int cowsAllocated = getAllocation(v, mid);

        /** If we are able to allocate all cows, then we push and see how much distance can be increased*/
        if(cowsAllocated >= cows) {
            minDistance = mid;
            low = mid + 1;
        }
        else {
            /** If allocation is not possible then we decrease the stall distance */
            high = mid - 1;
        }
    }
    return minDistance;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &it : v) {
        cin >> it;
    }

    int cows;
    cin >> cows;
    int ans = solve(v, cows);

    cout << ans << "\n";
    return 0;
}