class Solution {
public:
    int solve(string s1, string s2, int i , int j, vector<vector<int>>& memo) {
        int n = s1.size();
        int m = s2.size();
        if(i == n) return m - j;
        if(j == m) return n - i;
        if(memo[i][j] != -1) return memo[i][j];
        if(s1[i] == s2[j]) {
            memo[i][j] = 0 + solve(s1, s2, i+1, j+1, memo);
            return memo[i][j];
        }
        else {
            int mini = min( 1 + solve(s1, s2, i, j + 1, memo), 1 + solve(s1, s2, i+1, j, memo));
            memo[i][j] = min(mini, 1 + solve(s1, s2, i+1, j + 1, memo));
            return memo[i][j];
        }

    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        return solve(word1, word2, 0, 0, memo);
    }
};
