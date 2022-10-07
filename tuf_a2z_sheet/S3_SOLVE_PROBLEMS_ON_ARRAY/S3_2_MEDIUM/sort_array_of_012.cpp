#include <iostream>
#include <vector>

using namespace std;

void sort_array(vector<int> &v)
{
    int zeroPos = 0;
    int twoPos = v.size() - 1;
    int i = 0;
    while(i <= twoPos)
    {
        if(v[i] == 0)
            swap(v[zeroPos++], v[i++]);
        else
        if(v[i] == 2)
            swap(v[twoPos--], v[i]);
        else
            i++;
    }
}


int main()
{
    int n;
    cout << "Enter the length of the array\n";
    cin >> n;

    vector<int> v(n);
    cout << "Enter the array elements\n";
    for(int i = 0; i < n; i++)
        cin >> v[i];

    sort_array(v);

    cout << "The array after sorting is\n";
    for(int it : v)
        cout << it << " ";
    cout << "\n";

    return 0;
}