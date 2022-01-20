/**
 * GIVEN AN ARRAY HAVING THE PRICES OF STOCKS, WE HAVE 
 * TO MAXIMIZE THE PROFIT MADE BY BUYING &SELLING THE 
 * STOCKS.
 * 
 * INPUT : 1 5 3 8 12
 * OUTPUT : 8
 * 
 * INPUT : 30 20 10
 * OUTPUT : 0
 * 
 * INPUT : 10 20 30
 * OUTPUT : 20 
 * 
 * ALGORITHM (NAIVE) (RECURSIVE APPROACH)
 * ---------------------------------------
 * The basic idea is to traverse the array and
 * if at any point, the rightmost value is greater
 * than the left one, then recursively find the
 * profit for the left as well as right portion.
 * 
 * Keep on doing this and keep a track of the max
 * value obtained at any point of the recursive call.
 * At the end, return that tracked maximum value.
 * 
*/

#include <iostream>
using namespace std;

int maxProfit(int * price, int start, int end)
{
    if(end <= start)
        return 0;
    
    int profit = 0;
    for(int i=start; i<end; i++)
    {
        for(int j=i+1; j<=end; j++)
        {
            if(price[j] > price[i])
            {
                int currentProfit = price[j] - price[i] + maxProfit(price, start, i-1) + maxProfit(price, j+1, end);
                profit = max(profit, currentProfit);
            }
        }
    }
    return profit;
}


int main()
{
    int size;
    cout << "Enter the size of the array\n";
    cin >> size;

    int arr[size];
    cout << "Enter the array elements\n";

    for(int i=0;i<size;i++)
        cin >> arr[i];

    int profit = maxProfit(arr,0,size-1);
    cout << "Maximum profit = " << profit << "\n";
    return 0;
}