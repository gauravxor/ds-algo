#include <iostream>
#include <vector>
using namespace std;


int getMajority(vector<int> &v)
{
    int candidateCount = 0;
    int candidate = v[0];

    for(int i = 0; i < v.size(); i++)
    {
        if(candidateCount == 0)
            candidate = v[i];
        
        if(v[i] == candidate)
            candidateCount++;
        else
            candidateCount--;
    }


    candidateCount = 0;
    for(int i = 0; i < v.size(); i++)
        if(candidate == v[i])
            candidateCount++;

    if(candidateCount <= (v.size() / 2)) return -1;
    return candidate;
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
    
    int majority = getMajority(v);

    if(majority == -1)
        cout << "Majority element doesnot exist\n";
    else
        cout << "The majority element is " << majority << "\n";

    return 0;
}