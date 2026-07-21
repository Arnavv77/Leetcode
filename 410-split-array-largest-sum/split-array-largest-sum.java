import java.util.*;

class Solution {
    public int splitArray(int[] nums, int k) {
        int low = 0, high = 0;

        for (int num : nums) {
            low = Math.max(low, num);
            high += num;
        }

        int ans = high;

        // Binary Search on the answer range [low, high]
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid)) {
                ans = mid;        // 'mid' is a possible answer, try finding a smaller max sum
                high = mid - 1;
            } else {
                low = mid + 1;    // 'mid' is too small, try a larger sum
            }
        }

        return ans;
    }

    private boolean canSplit(int[] nums, int k, int maxSum) {
        int count = 1;
        int currSum = 0;

        for (int num : nums) {
            if (currSum + num <= maxSum) {
                currSum += num;
            } else {
                count++;
                currSum = num;
            }
        }
        return count <= k;
    }
}