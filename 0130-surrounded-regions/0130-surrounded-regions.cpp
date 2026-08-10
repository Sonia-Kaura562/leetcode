class Solution {
private:
    int dfs(int row, int col, int s, vector<vector<char>>& board,
            vector<vector<int>>& vis, vector<pair<int,int>>& cells) {

        vis[row][col] = 1;
        cells.push_back({row, col});

        int m = board.size();
        int n = board[0].size();

        if (row == 0 || col == 0 || row == m - 1 || col == n - 1)
            s = 1;

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

                s = dfs(r, c, s, board, vis, cells);
            }
        }

        return s;
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == 'O' && !vis[i][j]) {

                    vector<pair<int,int>> cells;

                    int s = dfs(i, j, 0, board, vis, cells);

                    if (!s) {
                        for (auto &cell : cells) {
                            board[cell.first][cell.second] = 'X';
                        }
                    }
                }
            }
        }
    }
};