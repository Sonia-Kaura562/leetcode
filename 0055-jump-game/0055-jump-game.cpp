class Solution {
public:
    bool solve(vector<int>& nums, int k, vector<int>& dp) {
        int n = nums.size();

        if (k == n - 1) {
            return true;
        }

        if (dp[k] != -1) {
            return dp[k];
        }

        for (int jump = nums[k]; jump >= 1; jump--) {
            if (n - 1 - k <= jump) {
                return dp[k] = true;
            }

            if (solve(nums, k + jump, dp)) {
                return dp[k] = true;
            }
        }

        return dp[k] = false;
    }

    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};