#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    // Helper function: counts subarrays with at most k distinct elements
    int helper(vector<int>& nums, int k) {
        if (k < 0) return 0;
        
        int l = 0, r = 0, cnt = 0;
        unordered_map<int, int> mpp;

        while (r < nums.size()) {
            mpp[nums[r]]++;

            // Shrink window when distinct elements exceed k
            while (mpp.size() > k) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) {
                    mpp.erase(nums[l]);
                }
                l++; 
            }

            cnt += (r - l + 1);
            r++;
        }

        return cnt;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Exactly(k) = AtMost(k) - AtMost(k - 1)
        return helper(nums, k) - helper(nums, k - 1);
    }
};