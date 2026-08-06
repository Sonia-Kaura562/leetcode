class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int currColor = image[sr][sc];
        int rowSize = image.size();
        int colSize = image[0].size();
        queue<pair<int, int>>q;
        q.push({sr, sc});
        image[sr][sc] = color;
        int adj[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        while(!q.empty()) {
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int adjRow = currRow + adj[i][0];
                int adjCol = currCol + adj[i][1];
                if(adjRow >= 0 && adjCol >= 0 && adjCol < colSize && adjRow < rowSize && adjCol < colSize && (image[adjRow][adjCol] == currColor) && (image[adjRow][adjCol] != color)) {
                    image[adjRow][adjCol] = color;
                    q.push({adjRow, adjCol});
                }
            }
        }

        return image;
    }
};