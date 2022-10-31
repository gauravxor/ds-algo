#include <iostream>
using namespace std;

int get_max_consecutive(int *arr, int length)
{
    int ans = 0;
    int sum = 0;

    for(int i = 0; i < length; i++)
    {
        sum *= arr[i];
        sum += arr[i];
        ans = max(ans, sum);
    }

    return ans;
}



int main()
{
    int len;
    cout << "Enter the length of array\n";
    cin >> len;

    int arr[len];

    cout << "Enter the elements of the array\n";
    for(int i = 0; i < len; i++)
        cin >> arr[i];


    cout << "Maximum number of consecutive ones is ";

    int ans = get_max_consecutive(arr, len);
    cout << ans << "\n";

    return 0;
}