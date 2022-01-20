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
 * ALGORITHM (EFFICIENT) (ITERATIVE APPROACH)
 * ---------------------------------------
 * THIS IS AN INTUITIVE APPROACH. WE OBSERVE THAT
 * WE SHOULD BUY THE STOCK WHEN THE PRICE IS LOW
 * AND SELL THE STOCK WHEN THE PRICE IS HIGH.
 * 
 * SUPPOSE THE EXAMPLE PRICE IS
 * 1 5 8 2 8 12
 * HERE, DURING THE FIRST THREE DAYS, THE STOCK PRICES
 * ARE GOING UP SO WE LET THEM GO UP AND WAIT TILL IT 
 * GOES DOWN AGAIN. SOON AS IT GOES DOWN, JUST BEFORE 
 * THAT POINT WE WILL SELL THE STOCK AS THAT POINT THE
 * PRICE OF THE CURRENT STOCK IS AT ITS PEAK.
 * 
 * WE WILL REPEAT THE PROCESS TILL THE END AND WE WILL
 * HAVE THE ANSWER WITH US.
*/


#include <iostream>
using namespace std;

int maxProfit(int * price, int size)
{
    int profit = 0;
    for(int i=1;i<size;i++)
    {
        if(price[i] > price[i-1])
            profit += price[i] - price[i-1];
    }
    return profit;
}

int main()
{
    int size;
    cout << "Enter the size of the array\n";
    cin >> size;

    int arr[size];

    cout << "Enter the elements in the array\n";
    for(int i=0;i<size;i++)
        cin >> arr[i];

    int profit = maxProfit(arr,size);
    cout << "The maximum profit is  = " << profit << "\n";
    return 0;

}