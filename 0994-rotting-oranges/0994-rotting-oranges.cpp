class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count = 0;
        int ans = 0;
        queue<pair<int, int>>q;
        vector<vector<int>> temp(grid);
        int dirRow[4] = {0, -1, 0, 1};
        int dirCol[4] = {-1, 0, 1, 0};
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if(grid[i][j] == 1) count++;
            }
        }

        while(!q.empty()) {
            int size = q.size();
            bool test = false;
            while(size--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int r = dirRow[i] + row;
                    int c = dirCol[i] + col;
                    if(r >= 0 and c >= 0 and r < m and c < n and temp[r][c] == 1) {
                        count--;
                        q.push({r, c});
                        test = true;
                        temp[r][c] = 2;
                    }
                }
            }
            if(test) ans++;
        }
        return !count ? ans : -1;
    }
};