class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int m = edges.size();
        vector<vector<int>> adj(n, vector<int>(n, 1e8));
        for(int i = 0; i < n; i++) {
            adj[i][i] = 0;
        }
        for(int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u][v] = w;
            adj[v][u] = w;
            
        }
        for(int via = 0; via < n; via++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(adj[i][via] != 1e8 and adj[via][j] != 1e8) {
                        adj[i][j] = min(adj[i][via] + adj[via][j], adj[i][j]);
                    }
                }
            }
        }

        vector<int> ans(n, 0);
         for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(adj[i][j] <= distanceThreshold) {
                    ans[i]++;
                }
            }
        }

        int res = 1e8;
        int fin;
        for(int i = 0; i < n; i++) {
            if(res >= ans[i]) {
                res = ans[i];
                fin = i;
            }
        }
        return fin;
    
    }
};