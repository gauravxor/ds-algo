/* A pair (v[i], v[j]) is a reverse pair when (i < j) & (v[i] > 2 * v[j]) */

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &v, int low, int mid, int high) {

    vector<int> left(mid - low + 1);
    vector<int> right(high - mid);
    int index = 0;

    for(int i = low; i <= mid; i++)
        left[index++] = v[i];

    index = 0;
    for(int i = mid + 1; i <= high; i++)
        right[index++] = v[i];

    index = low;
    int leftIndex = 0, rightIndex = 0;
    while(leftIndex < left.size() && rightIndex < right.size()) {
        if(left[leftIndex] <= right[rightIndex])
            v[index++] = left[leftIndex++];
        else
            v[index++] = right[rightIndex++];
    }
    while(leftIndex < left.size())
        v[index++] = left[leftIndex++];
    while(rightIndex < right.size())
        v[index++] = right[rightIndex++];
}

void countPairs(vector<int> &v, int low, int mid, int high, int &pairCount) {
    int counter = 0, rightPointer = mid + 1;
    for(int i = low; i <= mid; i++) {
        while(rightPointer <= high && v[i] > v[rightPointer] * 2)
            rightPointer++;
        pairCount += (rightPointer - (mid + 1));
    }
}
void mergeSort(vector<int> &v, int low, int high, int &pairCount) {
    if(low < high) {
        int mid = (low + high) / 2;
        mergeSort(v, low, mid, pairCount);
        mergeSort(v, mid + 1, high, pairCount);
        countPairs(v, low, mid, high, pairCount);
        merge(v, low, mid, high);
    }
}

using namespace std;
int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(auto &it: v)
        cin >> it;
    int pairCount = 0;
    mergeSort(v, 0, n - 1, pairCount);
    cout << "Reverse Pairs = " << pairCount << "\n";
    return 0;
}