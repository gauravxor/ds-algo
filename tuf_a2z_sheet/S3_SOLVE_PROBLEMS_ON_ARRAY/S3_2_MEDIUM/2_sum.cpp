#include <bits/stdc++.h>
using namespace std;


int get2Sum(vector<int> v, int target)
{
    unordered_set<int> s;

    for(int i = 0; i < v.size(); i++)
    {
        auto it = s.find(target - v[i]);
        if(it != s.end())
            return v[i];
        s.insert(v[i]);
    }
    return INT_MAX;
}


int main()
{
    int length;
    cout << "Enter the size of the array\n";
    cin >> length;

    vector<int> arr(length);

    cout << "Enter the elements of the array\n";
    for(int &it : arr)
        cin >> it;
    
    int target;
    cout << "Enter the target\n";
    cin >> target;

    int ans = get2Sum(arr, target);
    
    if(ans == INT_MAX)
        cout << "No suitable elements found\n";
    else
        cout << ans << " " << target - ans << "\n";
    return 0;
}