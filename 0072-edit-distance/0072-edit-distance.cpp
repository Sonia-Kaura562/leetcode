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
            int insert = 1 + solve(s1, s2, i, j + 1, memo);
            int del = 1 + solve(s1, s2, i+1, j, memo);
            int replace = 1 + solve(s1, s2, i+1, j + 1, memo);
            return memo[i][j] = min({insert, del, replace});
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        return solve(word1, word2, 0, 0, memo);
    }
};