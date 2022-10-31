#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



void generateNextPermutation(vector<int> &v)
{
    int i = 0, j = 0;
    for(i = v.size() - 1; i > 0; i--)
    {
        if(v[i] > v[i - 1])
            break;
    }
    if(i == 0)
        reverse(v.begin(), v.end());
    else
    {
        i--;
        for(j = v.size() - 1; j > i; j--)
        {
            if(v[j] > v[i])
                break;
        }
        swap(v[i], v[j]);
        reverse(v.begin() + i + 1, v.end());
    }

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


    generateNextPermutation(v);

    cout << "The next greater permutation is\n";
    for(int it: v)
        cout << it << " ";
    cout << "\n";
    return 0;
}