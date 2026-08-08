class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>>q;
        int count = 0;
        int fresh = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 2) q.push({i,j});
                else if(grid[i][j] == 1) fresh++;
            }
        }
        if(!q.size() && fresh) return -1;
        if(!q.size() && !fresh && grid.size()) return 0;
        //if(q.size() == grid.size()*grid[0].size()) return 0;
        int rowcol[4][2] = {
            {0, -1},
            {-1, 0},
            {0, 1},
            {1, 0}
        };
        while(!q.empty()) {
            count++;
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(int j = 0; j < 4; j++) {
                    int r = row + rowcol[j][0];
                    int c = col + rowcol[j][1];
                    if(r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size() && grid[r][c] == 1) {
                        grid[r][c] = 2;
                        fresh--;
                        q.push({r,c});
                    }
                } 
            }   
        }
            if(fresh) return -1;
            return --count;    
    }
};