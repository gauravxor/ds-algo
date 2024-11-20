/** https://leetcode.com/problems/majority-element/ */
package leetcode.easy;

public class lc_169 {
    public static int solve(int[] nums) {
        int majorityCount = 0;
        int currentMajoryElement = nums[0];
        for (int num : nums) {
            if (currentMajoryElement == num) {
                majorityCount += 1;
            } else {
                majorityCount -= 1;
            }

            if (majorityCount == 0) {
                majorityCount = 1;
                currentMajoryElement = num;
            }
        }
        return currentMajoryElement;
    }

    public static void main(String args[]) {
        int nums[] = { 2, 7, 11, 15, 7 };
        // int nums[] = { 3, 3 };

        int majorityElement = solve(nums);
        System.out.println("The majority element is = " + majorityElement);
    }
}
