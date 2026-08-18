class Solution {
public:
    int solve(int n, vector<int>& vis) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(!n) return 0;
        if(vis[n]) return vis[n];
        vis[n] = solve(n - 1, vis) + solve( n - 2, vis);
        return vis[n];
    }
    int climbStairs(int n) {
        vector<int>vis(n + 1, 0);
        return solve(n, vis);
    }
};