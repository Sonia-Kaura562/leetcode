class Solution {
private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int rowSize, int colSize, int adj[4][2], int currColor) {
        image[sr][sc] = color;
        for(int i = 0; i < 4; i++) {
            int adjRow = sr + adj[i][0];
            int adjCol = sc + adj[i][1];

            if(adjRow >= 0 and adjCol >= 0 and adjRow < rowSize and adjCol < colSize and image[adjRow][adjCol] == currColor and image[adjRow][adjCol] != color) {
                dfs(image, adjRow, adjCol, color, rowSize, colSize, adj, currColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<pair<int, int>>v;
        int rowSize = image.size();
        int colSize = image[0].size();
        int currColor = image[sr][sc];
        if (currColor == color)
            return image;
        int adj[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        dfs(image, sr, sc, color, rowSize, colSize, adj, currColor);
        return image;
    }
};