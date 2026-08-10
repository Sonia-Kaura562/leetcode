class Solution {
private:
    bool dfs(int row, int col, vector<vector<char>>& board,
             vector<vector<int>>& vis) {

        int m = board.size();
        int n = board[0].size();

        vis[row][col] = 1;

        bool touchBoundary = (row == 0 || col == 0 ||
                              row == m - 1 || col == n - 1);

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
                board[r][c] == 'O' && !vis[r][c]) {

                if (dfs(r, c, board, vis))
                    touchBoundary = true;
            }
        }

        return touchBoundary;
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == 'O' && !vis[i][j]) {

                    int before = 0;

                    dfs(i, j, board, vis);

                    bool boundary = false;

                    for (int r = 0; r < m; r++) {
                        for (int c = 0; c < n; c++) {
                            if (vis[r][c] == 1 &&
                                (r == 0 || c == 0 ||
                                 r == m - 1 || c == n - 1)) {
                                boundary = true;
                            }
                        }
                    }

                    if (!boundary) {
                        for (int r = 0; r < m; r++) {
                            for (int c = 0; c < n; c++) {
                                if (vis[r][c] == 1)
                                    board[r][c] = 'X';
                            }
                        }
                    }

                    for (int r = 0; r < m; r++) {
                        for (int c = 0; c < n; c++) {
                            if (vis[r][c] == 1)
                                vis[r][c] = 2;
                        }
                    }
                }
            }
        }
    }
};