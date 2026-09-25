class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dis(n, vector<int>(m, 1e9));
        deque<pair<int, int>>dq;
        dis[0][0] = 0;
        dq.push_front({0, 0});
        int dir_x[] = {0, 0, 1, -1};
        int dir_y[] = {1, -1, 0, 0}; 
        while(!dq.empty()) {
            int dr = dq.front().first;
            int dc = dq.front().second;
            dq.pop_front();

            for(int k = 0; k < 4; k++) {
                int x = dr + dir_x[k];
                int y = dc + dir_y[k];
                
                if(x >= 0 and y >= 0 and x < n and y < m) {
                    int cost;
                    if(grid[dr][dc] == k + 1) {
                        cost = 0;
                    }
                    else cost = 1;
                    if(dis[x][y] > dis[dr][dc] + cost) {
                        dis[x][y] = dis[dr][dc] + cost;
                        if(cost == 0) {
                            dq.push_front({x, y});
                        }
                        else {
                            dq.push_back({x, y});
                        }
                    }
                }
            }
        }
        return dis[n -1][m - 1];
    }
};