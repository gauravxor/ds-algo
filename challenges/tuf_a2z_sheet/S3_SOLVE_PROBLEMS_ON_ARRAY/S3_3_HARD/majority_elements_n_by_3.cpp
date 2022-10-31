#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int getMajority(vector<int> &v)
{
    int firstMajor = -1;
    int firstMajorCount = 0;

    int secondMajor = -1;
    int secondMajorCount = 0;

    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] == firstMajor)
            firstMajorCount++;
        else
        if(v[i] == secondMajor)
            secondMajorCount++;
        else
        if(firstMajorCount == 0)
        {
            firstMajor = v[i];
            firstMajorCount++;
        }
        else
        if(secondMajorCount == 0)
        {
            secondMajor = v[i];
            secondMajorCount++;
        }
        else
        {
            firstMajorCount--;
            secondMajorCount--;
        }
    }

    firstMajorCount = 0;
    secondMajorCount = 0;

    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] == firstMajor)
            firstMajorCount++;
        if(v[i] == secondMajor)
            secondMajorCount++;
    }

    if(firstMajorCount > v.size() / 3)
        return firstMajor;

    if(secondMajorCount > v.size() / 3)
        return secondMajor;

    return INT_MAX;
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

    int majority = getMajority(v);

    if(majority == INT_MAX)
        cout << "No Manjority Element Exists\n";
    else
        cout << "The majority element is = " << majority << "\n";

    return 0;
}