#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

int getBouquetsCount(vector<int> &days, int waitingDays, int adjacentFlowers) {
    int bouquetCount = 0, adjacentCount = 0;
    for(int day : days) {
        if(day <= waitingDays) {
            adjacentCount++;
        }
        else {
            adjacentCount = 0;
        }

        if(adjacentCount == adjacentFlowers) {
            bouquetCount++;
            adjacentCount = 0;
        }
    }
    return bouquetCount;
}

int getMinWaitTime(vector<int> &days, int bouquetsNeeded, int adjacentFlowers) {

    int minDays = 1;
    int maxDays = *max_element(days.begin(), days.end());

    while(minDays <= maxDays) {
        int currentDays = (minDays + maxDays) / 2;
        int bouquetsCount = getBouquetsCount(days, currentDays, adjacentFlowers);

        if(bouquetsCount < bouquetsNeeded) {
            minDays = currentDays + 1;
        }
        else {
            maxDays = currentDays - 1;
        }
    }
    if(minDays > *max_element(days.begin(), days.end()))
        return -1;
    return minDays;
}

int main () {
    int n;
    cin >> n;

    vector<int> days(n);
    for(auto &day: days)
        cin >> day;

    int bouquetsNeeded, adjacentFlowers;
    cin >> bouquetsNeeded >> adjacentFlowers;

    int minWaitTime = getMinWaitTime(days, bouquetsNeeded, adjacentFlowers);
    cout << minWaitTime << "\n";
    return 0;
}