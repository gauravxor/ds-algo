#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> getRanks(vector<int> &v) {
    set<int> st(v.begin(), v.end());
    int rank = 1;
    vector<int> rankVector(v.size());

    for(int i = 0; i < v.size(); i++) {
        int greaterElements = distance(st.upper_bound(v[i]), st.end());
        rankVector[i] = st.size() - greaterElements;
    }
    return rankVector;
}

int main () {
    int n;
    cin >> n;

    vector<int> v(n);
    for(auto &it : v) {
        cin >> it;
    }

    vector<int> ranks = getRanks(v);

    for(int i : ranks) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}