#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// sliding window based approach
// TC : O(n * n) | SC : O(1)
pair<int, int> getSubArray(vector<int> &v, int k)
{
    int firstIndex = 0, sum = 0;
    for(int i = 0; i < v.size();)
    {
        if(sum + v[i] == k)
            return {firstIndex, i};

        if(sum + v[i] > k)
            sum -= v[firstIndex++];
        else
            sum += v[i++];
    }
    return {-1, -1};
}


int main()
{
    int n;
    cout << "Enter the size of the vector\n";
    cin >> n;

    vector<int> v(n);

    cout << "Enter the vector elements\n";
    for(int i = 0; i < n; i++)
        cin >> v[i];

    int k;
    cout << "Enter the needed sum\n";
    cin >> k;

    pair<int, int> p = getSubArray(v, k);
    if(p.first == -1) 
        cout << "No such subarray exists\n";
    else
    {
        for(int i = p.first; i <= p.second; i++)
            cout << v[i] << " ";
        cout << "\n";
    }

    return 0;
}