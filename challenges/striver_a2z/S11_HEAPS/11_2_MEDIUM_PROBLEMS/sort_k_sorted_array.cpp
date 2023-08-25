/** K sorted array means an array, where in it's sorted from the ith element of the unsorted array
 *  can be present betweem (i - k) to (i + k)th position.
 *
 *  Eg.
 *  {9, 8, 7, 18, 19, 17}  K = 2
 */


#include <vector>
#include <iostream>
#include <queue>

using namespace std;

void solve(vector<int> &v, int k, vector<int> &res) {
    /** Creating a min heap */
    priority_queue<int, vector<int>, greater<int>> pq;
    int index = 0;

    /* Push first K element in the heap*/
    for(int i = 0; i <= k; i++) {
        pq.push(v[i]);
    }

    /** Taking the smallest form the minheap and inserting the next element*/
    for(int i = k + 1; i < v.size(); i++) {
        res[index++] = pq.top();
        pq.pop();
        pq.push(v[i]);
    }

    /** Including the remaining elements in the heap */
    while(!pq.empty()) {
        res[index++] = pq.top();
        pq.pop();
    }
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

    vector<int> result(n);
    solve(v, k, result);

    for(int i : result) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}