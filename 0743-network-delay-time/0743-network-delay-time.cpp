class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        for(auto it : times) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
        }
        pq.push({0, k});
        while(!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(dist[node] < wt) continue;
            for(auto& it : adj[node]) {
                int next = it.first;
                int nwt = it.second;
                if(wt + nwt < dist[next]) {
                    dist[next] = wt + nwt;
                    pq.push({dist[next], next});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(dist[i] == 1e9) return -1;
            ans = max(dist[i], ans);
            
        }
        return ans;
    }
};