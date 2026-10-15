class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>>ans(image);
         vector<vector<int>>vis(m, vector<int>(n));
        int sourColor = image[sr][sc];
        queue<pair<int, int>>q;
        int dirRow[4] = {0, -1, 0, 1};
        int dirCol[4] = {-1, 0, 1, 0};
        q.push({sr, sc});
        vis[sr][sc] = 1;
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            ans[row][col] = color;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int r = row + dirRow[i];
                int c = col + dirCol[i];
                if(r >= 0 and c >= 0 and r < m and c < n and ans[r][c] == sourColor and vis[r][c] == 0) {
                    vis[r][c] = 1;
                    q.push({r, c});
                }
            }
        }
        return ans;
    }
};