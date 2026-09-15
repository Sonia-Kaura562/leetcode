class Solution {
public:
    bool solve(vector<int>& nums, vector<int>& dp, int k) {
        if(dp[k] != -1) return dp[k];
        int size = nums.size();
        if(k >= size - 1) return true;
        for(int i = nums[k]; i >= 1; i--) {
            if(size - 1 - k <= i) {
                return dp[k] = true;
            }
            if(solve(nums, dp, i + k)) return dp[k] = true;;
        }
        return dp[k] = false;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(), -1);
        return solve(nums, dp, 0);
    }
};