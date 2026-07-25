class Solution {
private:
    int solve(vector<int>& coins, int amount, int index, vector<vector<int>>& memo) {
        if(memo[index][amount] != -1) {
            return memo[index][amount];
        }
        if(!amount) return 0;
        if(index == 0) {
            if(amount % coins[0] == 0) return amount/coins[0];
            return 1e7;
        }
        int take = 1e7;
        if(coins[index] <= amount) {
            take = 1 + solve(coins, amount - coins[index], index, memo);
        }
        int notTake = solve(coins, amount, index - 1, memo);
        return memo[index][amount] = min(take, notTake);
       
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, -1));
        int result = solve(coins, amount, coins.size() - 1, memo);
        return (result >= 1e7) ? -1 : result;
    }
};