#include <vector>
#include <iostream>
#include <climits>

using namespace std;

/** ! Optimal.  TC : O(N)  |  SC : O(N)  */
int getTrappedWater_1(vector<int> &heights) {
    int maxWater = 0;

    vector<int> rightMaxElements(heights.size());
    rightMaxElements.back() = heights.back();

    for(int i = heights.size() - 2; i >= 0;  i--) {
        rightMaxElements[i] = max(rightMaxElements[i + 1], heights[i]);
    }

    int currentLeftMax = INT_MIN;

    for(int i = 0; i < heights.size(); i++) {
        currentLeftMax = max(currentLeftMax, heights[i]);
        maxWater += abs(min(currentLeftMax, rightMaxElements[i]) - heights[i]);
    }
    return maxWater;
}


/** Optimal Code.  TC : O(N)  |  SC : O(1)  */
int getTrappedWater_2(vector<int> &heights) {
    int leftHeightMax = INT_MIN, leftIndex = 0;
    int rightHeightMax = INT_MIN, rightIndex = heights.size() - 1;
    int trappedWater = 0;
    while(leftIndex <= rightIndex) {
        if(heights[leftIndex] <= heights[rightIndex]) {
            leftHeightMax = max(leftHeightMax, heights[leftIndex]);
            trappedWater += leftHeightMax - heights[leftIndex];
            leftIndex++;
        }
        else {
            rightHeightMax = max(rightHeightMax, heights[rightIndex]);
            trappedWater += rightHeightMax - heights[rightIndex];
            rightIndex--;
        }
    }
    return trappedWater;
}

int main () {
    int n;
    cin >> n;

    vector<int> heights(n);
    for(auto &height : heights) {
        cin >> height;
    }

    int maxWater = getTrappedWater_2(heights);
    cout << "Trapped Water = " << maxWater << "\n";
    return 0;
}