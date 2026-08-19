class Solution {
public:
    int solve(int n, int prev2, int prev1) {
        if(n == 0) return prev1;

        int curr = prev1 + prev2;

        return solve(n - 1, prev1, curr);
    }

    int climbStairs(int n) {
        if(n == 1) return 1;
        return solve(n - 2, 1, 2);
    }
};