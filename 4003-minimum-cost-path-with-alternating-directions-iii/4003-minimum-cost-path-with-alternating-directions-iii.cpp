class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        const long long INF = 1e18;
        vector<vector<vector<long long >>> dist(m, vector<vector<long long>>(n, vector<long long>(2, INF)));

        priority_queue<
            tuple<long long, int, int , int>,
            vector<tuple<long long, int, int , int >>,
            greater<tuple<long long, int, int, int>>
        >pq;

        dist[0][0][0] = 1;
        pq.push({1, 0, 0, 0});
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while(!pq.empty()) {
            auto [cost, r, c, parity] = pq.top();
            pq.pop();

            if(cost != dist[r][c][parity]) continue;

            if(r == m-1 && c == n-1) return cost;
            int nextParity = parity^1;

            if(cost+penalty[r][c] < dist[r][c][nextParity]) {
                dist[r][c][nextParity] = cost+penalty[r][c];
                pq.push({dist[r][c][nextParity], r, c, nextParity});
            }

            for(int k = 0; k < 4; k++) {
                int nr = r+dr[k];
                int nc = c + dc[k];

                if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                long long add = (long long)(nr + 1)*(nc + 1);

                bool allowed = false;

                if(!parity) {
                    if((dr[k] == 1&&dc[k] == 0) || (dr[k] == 0&&dc[k] == 1))
                     allowed = true;   
                }
                else {
                    if((dr[k] == -1&&dc[k] == 0) || (dr[k] == 0&&dc[k] == -1))
                        allowed = true;
                }

                if(!allowed)
                    add+=penalty[r][c];

                if(cost+add<dist[nr][nc][nextParity]) {
                    dist[nr][nc][nextParity] = cost+add;
                    pq.push({dist[nr][nc][nextParity], nr, nc, nextParity});
                }
            }
        }
        return -1;
    }
};