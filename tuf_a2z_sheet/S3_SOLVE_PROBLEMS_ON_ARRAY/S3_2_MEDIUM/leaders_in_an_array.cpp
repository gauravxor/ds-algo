#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



vector<int> printLeaders(vector<int> &v)
{
    vector<int> leaders;
    int currentMax = v[v.size() - 1];
    leaders.push_back(currentMax);
    for(int i = v.size() - 2; i >= 0; i--)
    {
        if(v[i] > currentMax)
            leaders.push_back(v[i]);
        currentMax = max(currentMax, v[i]);
    }
    return leaders;
}

int main()
{
    int n;
    // cout << "Enter the size of the vector\n";
    cin >> n;

    vector<int> v(n);

    // cout << "Enter the vector elements\n";
    for(auto &it : v)
        cin >> it;


    vector<int> leaders = printLeaders(v);

    reverse(leaders.begin(), leaders.end());
    for(int it : leaders)
        cout << it << " ";
    cout << "\n";
    return 0;
}