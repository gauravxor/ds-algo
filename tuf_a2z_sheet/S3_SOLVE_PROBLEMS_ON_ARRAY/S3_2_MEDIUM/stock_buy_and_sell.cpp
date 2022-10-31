#include <iostream>
#include <vector>

using namespace std;



int getMaxProfit(vector<int> &v)
{
    int maxProfit = 0, lowestCP = v[0];
    for(int i = 0; i < v.size(); i++)
    {
        lowestCP = min(lowestCP, v[i]);
        maxProfit = max(maxProfit, v[i] - lowestCP);
    }
    return maxProfit;
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


    int ans = getMaxProfit(v);

    cout << "The max profit is = " << ans << "\n";
    return 0;
}