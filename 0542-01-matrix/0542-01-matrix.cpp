class Solution {
private:
    void bfs(vector<vector<int>>& mat, vector<vector<int>>& vis, queue<pair<int, int>>&q) {
        int rowSize = mat.size();
        int colSize = mat[0].size();
        int adj[4][2] = {
            {0, -1},
            {-1, 0},
            {0, 1},
            {1, 0}
        };
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(auto i : adj) {
                int adjR = r + i[0];
                int adjC = c + i[1];
                if(adjR >= 0 and adjC >= 0 and adjR < rowSize and adjC < colSize and mat[adjR][adjC] and !vis[adjR][adjC]) {
                    mat[adjR][adjC] = mat[r][c] + 1;
                    vis[adjR][adjC] = 1;
                    q.push({adjR, adjC});
                }
            }
            // for(int i = 0; i < 4; i++) {
            //     int adjR = r + adj[i][0];
            //     int adjC = c + adj[i][1];
            //     if(adjR >= 0 and adjC >= 0 and adjR < rowSize and adjC < colSize and mat[adjR][adjC] and !vis[adjR][adjC]) {
            //         mat[adjR][adjC] = mat[r][c] + 1;
            //         vis[adjR][adjC] = 1;
            //         q.push({adjR, adjC});
            //     }
            // }
        }
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>>q;
        int rowSize = mat.size();
        int colSize = mat[0].size();
        vector<vector<int>>vis(rowSize, vector<int>(colSize, 0));
        for(int i = 0; i < rowSize; i++) {
            for(int j = 0; j < colSize; j++) {
                if(!mat[i][j]) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        bfs(mat, vis, q);
        return mat;
    }
};