#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;
long long int getTimeToEat(vector<int> &piles, int eatingRate) {
    long long int totalTimeNeeded = 0;
    for(int pile : piles)
        totalTimeNeeded += ceil((double) pile / eatingRate);
    return totalTimeNeeded;
}

int getMinBananas(vector<int> &piles, int hours) {

    int minBananas = 1;
    int maxBananas = *max_element(piles.begin(), piles.end());

    while(minBananas <= maxBananas) {
        int bananaCount = (minBananas + maxBananas) / 2;
        long long int timeToEat = getTimeToEat(piles, bananaCount);

        if(timeToEat <= hours) {
            maxBananas = bananaCount - 1;
        }
        else {
            minBananas = bananaCount + 1;
        }
    }
    return minBananas;
}

int main () {
    int n;
    cin >> n;

    vector<int> piles(n);
    for(auto &pile: piles)
        cin >> pile;

    int hours;
    cin >> hours;

    int minBananas = getMinBananas(piles, hours);
    cout << minBananas << "\n";
    return 0;
}