#include <vector>
#include <queue>
#include <iostream>

using namespace std;


int partition(vector<int> &v, int low, int high) {
    int pivotElement = v[high];
    int pivotIndex = low;

    for(int i = low; i < high; i++) {
        if(v[i] <= pivotElement) {
            swap(v[pivotIndex++], v[i]);
        }
    }
    swap(v[pivotIndex], v[high]);
    return pivotIndex;
}

int getKthSmallest_quickSelect(vector<int> &v, int low, int high, int k) {
    int pivotIndex = partition(v, low, high);
    if(pivotIndex == k) {
        return v[pivotIndex];
    }

    if(pivotIndex < k) {
        return getKthSmallest_quickSelect(v, pivotIndex + 1, high, k);
    }
    else {
        return getKthSmallest_quickSelect(v, low, pivotIndex - 1, k);
    }
    return -1;
}


int getKthSmallest_pq(vector<int> &v, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i : v) {
        pq.push(i);
    }

    while(k--) {
        pq.pop();
    }
    return pq.top();
}

int main () {
    int n;
    cin >> n;

    vector<int> v(n);
    for(auto &it : v) {
        cin >> it;
    }

    int k;
    cin >> k;

    // int kthSmallest = getKthSmallest_quickSelect(v, 0, n - 1, k - 1);
    int kthSmallest = getKthSmallest_pq(v, k - 1);
    cout << "Kth Smallest = " << kthSmallest << "\n";
    return 0;
}