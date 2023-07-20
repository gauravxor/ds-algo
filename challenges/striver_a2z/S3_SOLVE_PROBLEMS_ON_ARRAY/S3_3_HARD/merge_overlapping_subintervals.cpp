#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &v) {
    sort(v.begin(), v.end());
    vector<vector<int>> mergedIntervals;

    int previousStart = 0, previousEnd = 0;
    for(int i = 0; i < v.size(); i++) {
        previousStart = v[i][0];
        previousEnd = v[i][1];

        /** Check if need to process the current interval or it has been already processed */
        if(mergedIntervals.size() != 0 && previousEnd <= mergedIntervals.back()[1])
            continue;

        int index = i + 1;
        while(index < v.size() && previousEnd >= v[index][0]) {
            /** Update the end of current interval */
            previousEnd = max(previousEnd, v[index][1]);
            index++;
        }
        mergedIntervals.push_back({previousStart, previousEnd});
    }
    return mergedIntervals;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(2));
    for(auto &it : v)
        cin >> it[0] >> it[1];

    vector<vector<int>> ans = mergeIntervals(v);
    cout << "After merging the intervals\n";
    for(auto it: ans)
        cout << it[0] << " " << it[1] << "\n";
    return 0;
}