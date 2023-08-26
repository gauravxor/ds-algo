/** Brute force approach */
#include <vector>
#include <iostream>

using namespace std;


void merge(vector<int> &v1, vector<int> &v2) {
    vector<int> mergedArray(v1.size() + v2.size());
    int leftIndex = 0, rightIndex = 0;
    int index = 0;
    while(leftIndex < v1.size() && rightIndex < v2.size()) {
        if(v1[leftIndex] <= v2[rightIndex]) {
            mergedArray[index++] = v1[leftIndex++];
        }
        else {
            mergedArray[index++] = v2[rightIndex++];
        }
    }

    while(leftIndex < v1.size()) {
        mergedArray[index++] = v1[leftIndex++];
    }
    while(rightIndex < v2.size()) {
        mergedArray[index++] = v2[rightIndex++];
    }

    v1 = mergedArray;
}

vector<int> mergeArray(vector<vector<int>> &v) {
    vector<int> mergedArray;
    int index = 0;

    for(int i = 0; i < v.size(); i++) {
        merge(mergedArray, v[i]);
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