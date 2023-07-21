/* A pair is called inversed pair when (v[i], v[j]) where (i < j and v[i] > v[j]) */


#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &v, int low, int mid, int high, int &inversions) {
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
    int count = 0;

    while(leftIndex < left.size() && rightIndex < right.size()) {
        if(left[leftIndex] > right[rightIndex]) {
            count += (left.size() - leftIndex);
            v[index++] = right[rightIndex++];
        }
        else
            v[index++] = left[leftIndex++];
    }
    inversions += count;
    while(leftIndex < left.size())
        v[index++] = left[leftIndex++];
    while(rightIndex < right.size())
        v[index++] = right[rightIndex++];
}


void mergeSort(vector<int> v, int low, int high, int &inversions) {
    if(low < high) {
        int mid = (low + high) / 2;
        mergeSort(v, low, mid, inversions);
        mergeSort(v, mid + 1, high, inversions);
        merge(v, low, mid, high, inversions);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &it: v)
        cin >> it;
    int inversions = 0;
    cout << "Inversions = " << inversions << "\n";
    return 0;
}
