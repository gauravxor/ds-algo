/** Brute force approach */
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Triplet {

public:

    int val;
    int vectorIndex;
    int elementIndex;

    Triplet() {
        this->val = 0;
        this->vectorIndex = 0;
        this->elementIndex = 0;
    }

    Triplet(int val, int vectorIndex, int elementIndex) {
        this->val = val;
        this->vectorIndex = vectorIndex;
        this->elementIndex = elementIndex;
    }
};

class MyComp {
public:
    bool operator() (Triplet t1, Triplet t2) {
        return (t1.val > t2.val);
    }
};


vector<int> mergeArray(vector<vector<int>> &v) {

    priority_queue<Triplet, vector<Triplet>, MyComp> pq;

    for(int i = 0; i < v.size(); i++) {
        Triplet t(v[i][0], i, 1);
        pq.push(t);
    }

    vector<int> mergedArray;
    while(!pq.empty()) {
        int element = pq.top().val;
        int vectorIndex = pq.top().vectorIndex;
        int elementIndex = pq.top().elementIndex;

        mergedArray.push_back(element);

        pq.pop();

        if(elementIndex < v[vectorIndex].size()) {
            Triplet new_t(v[vectorIndex][elementIndex], vectorIndex, elementIndex + 1);
            pq.push(new_t);
        }
    }
    return mergedArray;
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