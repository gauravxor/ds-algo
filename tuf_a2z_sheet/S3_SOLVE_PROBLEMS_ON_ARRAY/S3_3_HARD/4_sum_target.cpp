#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> getQuadruplets(vector<int> &v, int target)
{
    sort(v.begin(), v.end());
    vector<vector<int>> ans;
    for(int i = 0; i < v.size(); i++)
    {
        long firstTarget = target - v[i];

        for(int j = i + 1; j < v.size(); j++)
        {
            long secondTarget = firstTarget - v[j];

            int low = j + 1;
            int high = v.size() - 1;

            while(low < high)
            {
                if(v[low] + v[high] == secondTarget)
                {
                    vector<int> temp = {v[i], v[j], v[low], v[high]};
                    ans.push_back(temp);
                
                    while(low < high && v[low] == v[low + 1]) low++;
                    while(low < high && v[high] == v[high - 1]) high--;

                    low++;
                    high--;
                }
                else
                if(v[low] + v[high] < secondTarget)
                    low++;
                else
                    high--;
            }

            while(j < v.size() - 1 && v[j] == v[j + 1]) j++;
        }

        while(i < v.size() - 1 && v[i] == v[i + 1]) i++;
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


    cout << "Enter the target\n";
    int target;
    cin >> target;
    vector<vector<int>> triplets = getQuadruplets(v, target);

    if(triplets.size() == 0)
        cout << "No such quadruplets exists\n";
    else
    {
        for(int i = 0; i < triplets.size(); i++)
        {
            for(int j = 0; j < 4; j++)
                cout << triplets[i][j] << " ";
            cout << "\n";
        }
    }   
    return 0; 
}