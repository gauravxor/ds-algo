#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/** TC : O(N) + O(K * log(K))
 *  O(N) -> To insert in priority queue
 *  O(K) -> To traverse K elements for deletion
 *  O(log K) -> To remove K elements from priority queue. (Insert/Delete takes logN in PQ)
*/
int getKthLargest_pq(vector<int> &v, int k) {
    priority_queue<int> pq;
    for(int i : v) {
        pq.push(i);
    }

    while(k > 1) {
        pq.pop();
        k--;
    }
    return pq.top();
}

int partition(vector<int> &v, int low, int high) {
    int pivotElement = v[high];
    int pivotIndex = low;
    for(int i = low; i <= high - 1; i++) {
        if(v[i] <= pivotElement) {
            swap(v[pivotIndex++], v[i]);
        }
    }
    swap(v[pivotIndex], v[high]);
    return pivotIndex;
}

/**  TC : O(N * log(K))  SC : O(k)*/
int getKthLargest_quickSelect(vector<int> &v, int low, int high, int k) {
    int pivotIndex = partition(v, low, high);
    if(pivotIndex + k == v.size()) {
        return v[pivotIndex];
    }

    if(pivotIndex + k >  v.size()) {
        return getKthLargest_quickSelect(v, low, pivotIndex - 1, k);
    }
    else {
        return getKthLargest_quickSelect(v, pivotIndex + 1, high, k);
    }
    return -1;
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

    // int KthLargest = getKthLargest_pq(v, k);
    int KthLargest = getKthLargest_quickSelect(v, 0, v.size() - 1, k);
    cout << "Kth Largest = " << KthLargest << "\n";
    return 0;
}