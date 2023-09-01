#include <vector>
#include <iostream>
using namespace std;

int s1(vector<int> &v) {
    int p1 = 0, p2 = 0, ans = 0;
    for(int i = 0; i < v.size(); i++) {
        ans = max(p1 + v[i], p2);
        p1 = max(p1, p2);
        p2 = ans;
    }
    return ans;
}
int main () {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &it : v) {
        cin >> it;
    }
    if(n == 1) {
        cout << v[0] << "\n";
        return 0;
    }
    vector<int> v1(v.begin() + 1, v.end());
    vector<int> v2(v.begin(), v.end() - 1);
    int ans = max(s1(v1), s1(v2));
    cout << ans << "\n";
    return 0;
}