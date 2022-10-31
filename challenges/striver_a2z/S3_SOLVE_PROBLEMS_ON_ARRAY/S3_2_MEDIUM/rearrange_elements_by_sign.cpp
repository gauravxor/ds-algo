#include <iostream>
#include <vector>
using namespace std;



void reArrange(vector<int> &v)
{
    int positiveIndex = 0;
    int negativeIndex = 1;
    for(int i = 0; positiveIndex < v.size(); i++)
    {
        if(v[i] >= 0)
        {
            swap(v[i], v[positiveIndex]);
            positiveIndex += 2;
        }
    }

    for(int i = 0; negativeIndex < v.size(); i++)
    {
        if(v[i] < 0)
        {
            swap(v[i], v[negativeIndex]);
            negativeIndex += 2;
        }
    }
    return;
}

int main()
{
    int n;
    cout << "Enter the size of the vector\n";
    cin >> n;
    vector<int> v(n);

    cout << "Enter the elements of the vector\n";
    for(auto &it : v)
        cin >> it;

    reArrange(v);

    cout << "The vector after rearranging\n";
    for(int it : v)
        cout << it << " ";
    cout << "\n";

    return 0;
}