class Solution {
public:
int maxScore(vector<int>& nums, int k) {
    int lsum = 0, rsum = 0, maxSum = 0;
    int n = nums.size();

    // Sum the first k elements from the left
    for (int i = 0; i < k; i++) {
        lsum += nums[i];
    }
    maxSum = lsum;

    int rIndex = n - 1;

    // Shift window: remove from left, add from right
    for (int i = k - 1; i >= 0; i--) {
        lsum -= nums[i];
        rsum += nums[rIndex];
        rIndex--;
        maxSum = max(maxSum, lsum + rsum);
    }

    return maxSum;
}
};