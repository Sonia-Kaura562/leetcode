class Solution {
private:
    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<int>>& vis) {
        int m = board.size();
        int n = board[0].size();
        vis[r][c] = 1;
        int adj[4][2] = {
            {0, -1},
            {-1, 0},
            {0, 1},
            {1, 0}
        };
        for(int i = 0; i < 4; i++) {
            int row = r + adj[i][0];
            int col = c + adj[i][1];

            if(row >= 0 and col >= 0 and row < m and col < n and !vis[row][col] and board[row][col] == 'O') {
                dfs(row, col, board, vis);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j  = 0; j < n; j++) {
                if((!vis[i][j] and board[i][j] == 'O') and (i == 0 or j == 0 or i == m - 1 or j == n - 1)) {
                    dfs(i, j, board, vis);
                } 
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j] and board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};