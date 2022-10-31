#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> getTriplets(vector<int> &v)
{
    sort(v.begin(), v.end());
    vector<vector<int>> ans;

    for(int i = 0; i < v.size() - 2; i++)
    {
        if(i == 0 || (v[i] != v[i - 1]))
        {
            int low = i + 1;
            int high = v.size() - 1;
            int target = -v[i];

            while(low < high)
            {
                if(v[low] + v[high] == target)
                {
                    vector<int> temp = {v[i], v[low], v[high]};
                    ans.push_back(temp);
                
                    while(low < high && v[low] == v[low + 1]) low++;
                    while(low < high && v[high] == v[high - 1]) high--;

                    low++;
                    high--;
                }
                else
                    (v[low] + v[high] < target)? low++ : high--;
            }
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
    cout << "Enter the elements of the vector\n";
    for(int i = 0; i < n; i++)
        cin >> v[i];

    vector<vector<int>> triplets = getTriplets(v);

    if(triplets.size() == 0)
        cout << "No such tripets exists\n";
    else
    {
        for(int i = 0; i < triplets.size(); i++)
        {
            for(int j = 0; j < 3; j++)
                cout << triplets[i][j] << " ";
            cout << "\n";
        }
    }   
    return 0; 
}