class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        board[row][col] = '#';

        int adj[4][2] = {
            {0, -1},
            {-1, 0},
            {0, 1},
            {1, 0}
        };

        for (int i = 0; i < 4; i++) {
            int r = row + adj[i][0];
            int c = col + adj[i][1];

            if (r >= 0 && c >= 0 && r < m && c < n &&
                board[r][c] == 'O') {
                dfs(r, c, board);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                dfs(i, 0, board);

            if (board[i][n - 1] == 'O')
                dfs(i, n - 1, board);
        }

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O')
                dfs(0, j, board);

            if (board[m - 1][j] == 'O')
                dfs(m - 1, j, board);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};