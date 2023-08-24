/** Given a vector containing some integer data. We need to find the number of elements that are strictly
 *  greater than the element of the current index to the right.
*/
#include <iostream>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

vector<int> countGreaterElements(vector<int> &v) {
    multiset<int> ms;
    vector<int> result(v.size());

    for(int i = v.size() - 1; i >= 0; i--) {
        result[i] = distance(ms.upper_bound(v[i]), ms.end());
        ms.insert(v[i]);
    }
    return result;
}

int main () {
    int n;
    cin >> n;

    vector<int> v(n);
    for(auto &it : v) {
        cin >> it;
    }

    vector<int> ans = countGreaterElements(v);

    for(int i : ans) {
        cout << i << " ";
    }
    cout << "\n";
}