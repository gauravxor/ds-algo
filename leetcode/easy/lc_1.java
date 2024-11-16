/** https://leetcode.com/problems/two-sum/description/ */

package leetcode.easy;

import java.util.HashMap;

class lc_1 {

    public static int[] solve(int[] nums, int target) {
        HashMap<Integer, Integer> hmap = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++) {
            if (hmap.containsKey(target - nums[i])) {
                return new int[] { hmap.get(target - nums[i]), i };
            } else {
                hmap.put(nums[i], i);
            }
        }
        return new int[] { -1, -1 };
    }

    public static void main(String args[]) {
        // int nums[] = { 2, 7, 11, 15 };
        int nums[] = { 3, 3};
        int target = 6;

        int result[] = solve(nums, target);
        System.out.println(result[0] + " " + result[1]);
    }
}