/** https://leetcode.com/problems/sort-colors/description/ */
package leetcode.medium;

public class lc_75 {
    public static void swap(int[] nums, int indexForRedOrBlue, int mainIndex) {
        int temp = nums[indexForRedOrBlue];
        nums[indexForRedOrBlue] = nums[mainIndex];
        nums[mainIndex] = temp;
    }

    public static void solve(int[] nums) {
        int mainIndex = 0;
        int indexForRed = 0;
        int indexForBlue = nums.length - 1;

        while (mainIndex <= indexForBlue) {
            if (nums[mainIndex] == 0)
                swap(nums, indexForRed++, mainIndex++);
            else if (nums[mainIndex] == 2)
                swap(nums, indexForBlue--, mainIndex);
            else
                mainIndex++;
        }
    }

    public static void main(String args[]) {
        int nums[] = { 1, 0, 2, 1, 0, 0 };
        solve(nums);
        for (int num : nums) {
            System.out.println(num + " ");
        }
    }
}
