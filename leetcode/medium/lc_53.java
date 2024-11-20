/** https://leetcode.com/problems/maximum-subarray/description/ */
package leetcode.medium;

public class lc_53 {

    public static int solve(int[] nums) {
        int maxSum = nums[0];
        int currentMax = nums[0];

        for (int i = 1; i < nums.length; i++) {
            currentMax = Math.max(currentMax + nums[i], nums[i]);
            maxSum = Math.max(maxSum, currentMax);
        }
        return maxSum;
    }

    public static void main(String args[]) {
        // int nums[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
        // int nums[] = {1};
        int nums[] = {5,4,-1,7,8};
        int max_sum = solve(nums);
        System.out.println("Maximum sum = " + max_sum);
    }
}