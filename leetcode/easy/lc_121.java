/** https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description */
package leetcode.easy;

public class lc_121 {
    public static int solve(int[] prices) {
        int minimumCostPrice = prices[0];
        int maxProfit = 0;

        for (int currentPrice : prices) {
            minimumCostPrice = Math.min(minimumCostPrice, currentPrice);
            maxProfit = Math.max(maxProfit, currentPrice - minimumCostPrice);
        }
        return maxProfit;
    }

    public static void main(String args[]) {
        int prices[] = { 7, 6, 4, 3, 1 };
        int maxProfit = solve(prices);
        System.out.println("The maximum profit = " + maxProfit);
    }
}
