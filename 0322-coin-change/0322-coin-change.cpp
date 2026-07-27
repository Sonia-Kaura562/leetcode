class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();
        vector<vector<int>>tabu(size + 1, vector<int>(amount + 1, 1e7));
        for(int i = 0; i <= size; i++) {
            tabu[i][0] = 0;
        }
        for(int i  = 1; i <= size; i++) {
            for(int j = 1; j <= amount; j++) {
                tabu[i][j] = tabu[i -1][j];
                if(j >= coins[i-1])
                tabu[i][j] = min(tabu[i][j], 1 + tabu[i][j - coins[i - 1]]);
            }
        }

        return tabu[size][amount] >= 1e7 ? -1 : tabu[size][amount];
    }
};