#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// BRUTEFORCE -> TC : O(n) | SC : O(1)
int longestConsecutiveBrute(vector<int> &v)
{
    sort(v.begin(), v.end());

    int count = 1, ans = 1;

    for(int i = 0; i < v.size() - 1; i++)
    {
        if(v[i + 1] - v[i] <= 1)
            count += v[i + 1] - v[i];
        else
            count = 1;
        ans = max(ans, count);
    }
    return ans;
}


// OPTIMAL -> TC : O(n) : SC : O(n)
int longestConsecutiveOpt(vector<int> &v)
{
    set<int> hash(v.begin(), v.end());

    int ans = 0;
    for(int it: v)
    {
        if(hash.count(it - 1) == 0)
        {
            int count = 1, currentElement = it;
            while(hash.count(currentElement + 1))
            {
                count++;
                currentElement++;
            }
            ans = max(ans, count);
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the vector\n";
    cin >> n;

    vector<int> v(n);


    cout << "Enter the vector elements\n";
    for(auto &it : v)
        cin >> it;
    
    int longestStreak = longestConsecutiveOpt(v);

    cout << "longest consecutive seq.'s  = " << longestStreak << "\n";
    return 0;

}