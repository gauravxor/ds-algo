#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> mergeArray(vector<vector<int>> &v) {
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for(int i = 0; i < v.size(); i++) {
        pq.push({v[i][0], i, 1});
    }

    vector<int> ans;

    while(pq.empty() == false) {
        int topElement = pq.top()[0];
        int vectorIndex = pq.top()[1];
        int elementIndex = pq.top()[2];

        ans.push_back(topElement);

        if(elementIndex < v[vectorIndex].size()) {
            pq.push({v[vectorIndex][elementIndex], vectorIndex, elementIndex + 1});
        }
        pq.pop();
    }
    return ans;
}


int main () {
    int count;
    cin >> count;

    vector<vector<int>> v;

    while(count--) {
        int size;
        cin >> size;
        vector<int> arr(size);
        for(auto &it : arr) {
            cin >> it;
        }
        v.push_back(arr);
    }

    vector<int> mergedArray = mergeArray(v);

    for(int i : mergedArray) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}