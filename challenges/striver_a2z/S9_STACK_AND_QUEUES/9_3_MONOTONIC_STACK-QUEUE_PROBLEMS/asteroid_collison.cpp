#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> collideAsteroids(vector<int> &asteroids) {
    vector<int> result;
    for(int i = 0; i < asteroids.size(); i++) {
        if(asteroids[i] > 0 || result.size() == 0 || result.back() < 0) {
            result.push_back(asteroids[i]);
        }
        else
        if(result.back() <= abs(asteroids[i])) {
            if(result.back() < abs(asteroids[i])) {
                i--;
            }
            result.pop_back();
        }
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

    vector<int> result = collideAsteroids(v);

    for(int i : result) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}