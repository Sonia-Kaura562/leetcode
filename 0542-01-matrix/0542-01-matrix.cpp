class Solution {
private:
    void bfs(vector<vector<int>>& mat, queue<pair<int, int>>& q) {
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

                if(adjR >= 0 && adjC >= 0 &&
                   adjR < rowSize && adjC < colSize &&
                   mat[adjR][adjC] == -1) {

                    mat[adjR][adjC] = mat[r][c] + 1;
                    q.push({adjR, adjC});
                }
            }
        }
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;

        int rowSize = mat.size();
        int colSize = mat[0].size();

        for(int i = 0; i < rowSize; i++) {
            for(int j = 0; j < colSize; j++) {

                if(mat[i][j] == 0) {
                    q.push({i, j});
                }
                else {
                    mat[i][j] = -1;
                }
            }
        }

        bfs(mat, q);

        return mat;
    }
};