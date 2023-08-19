#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;


int getAllocation(vector<int> &v, int maxAllowedPages) {
    int studentCount = 1;
    int pagesAllocated = 0;
    for(int i = 0; i < v.size(); i++) {
        if(pagesAllocated + v[i] <= maxAllowedPages) {
            pagesAllocated += v[i];
        }
        else {
            studentCount += 1;
            pagesAllocated = v[i];
        }
    }
    return studentCount;
}

int solve(vector<int> &v, int students) {

    if(students > v.size()) {
        return -1;
    }

    /** The minimum number of pages (max) a student can read is the book with max pages.*/
    int low = *max_element(v.begin(), v.end());

    /** The max number of pages a student can read is, if he is allocated all books */
    int high = accumulate(v.begin(), v.end(), 0);

    while(low <= high) {
        int mid = (low + high) / 2;

        int studentsAllocated = getAllocation(v, mid);

        /** If more students are allocated, that means less pages are being assigned so we
         * need to increase the number of allocated pages to each students*/
        if(studentsAllocated > students) {
            low = mid + 1;
        }
        else {
            /** If less students are allocated, indicating high page allocation, we decrease,
             *  the allocation count */
            high = mid - 1;
        }
    }

    return low;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &it : v) {
        cin >> it;
    }

    int students;
    cin >> students;

    int ans = solve(v, students);
    cout << ans << "\n";
    return 0;
}