class Solution {
private:
    int solve(vector<int>& coins, int amount, int index,
              vector<vector<int>>& memo) {
        int size = coins.size() - 1;
        if (amount == 0)
            return 0;

        if (index == size) {
            if (amount % coins[size] == 0)
                return amount / coins[size];
            return 1e7;
        }

        if (memo[index][amount] != -1)
            return memo[index][amount];

        int take = 1e7;

        if (coins[index] <= amount) {
            take = 1 + solve(coins, amount - coins[index], index, memo);
        }

        int notTake = solve(coins, amount, index + 1, memo);

        return memo[index][amount] = min(take, notTake);
    }

public:
    int coinChange(vector<int>& coins, int amount) {

        vector<vector<int>> memo(coins.size(),
        vector<int>(amount + 1, -1));

        int ans = solve(coins, amount, 0, memo);

        return (ans >= 1e7) ? -1 : ans;
    }
};