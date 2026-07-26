class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        const int INF = 1e7;

        vector<vector<int>> tabu(n + 1, vector<int>(amount + 1, INF));

        // Base case
        for (int i = 0; i <= n; i++)
            tabu[i][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {

                // Not take
                tabu[i][j] = tabu[i - 1][j];

                // Take
                if (coins[i - 1] <= j) {
                    tabu[i][j] = min(
                        tabu[i][j],
                        1 + tabu[i][j - coins[i - 1]]
                    );
                }
            }
        }

        return (tabu[n][amount] >= INF) ? -1 : tabu[n][amount];
    }
};