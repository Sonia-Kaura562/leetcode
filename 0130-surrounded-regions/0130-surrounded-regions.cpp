class Solution {
private:
    void dfs(int r, int c, vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        board[r][c] = '#';
        int adj[4][2] = {
            {0, -1},
            {-1, 0},
            {0, 1},
            {1, 0}
        };
        for(int i = 0; i < 4; i++) {
            int row = r + adj[i][0];
            int col = c + adj[i][1];

            if(row >= 0 and col >= 0 and row < m and col < n and board[row][col] == 'O') {
                dfs(row, col, board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        //vector<vector<int>>vis(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {   
           if(board[i][0] == 'O') {
                dfs(i, 0, board);
           }
           if(board[i][n-1] == 'O') {
                dfs(i, n - 1, board);
           }
        }
        for(int j  = 0; j < n; j++) {
            if(board[0][j] == 'O') {
                dfs(0, j, board);
            }
            if(board[m-1][j] == 'O') {
                dfs(m-1, j, board);
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};