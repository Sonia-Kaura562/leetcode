class Solution {
public:
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges, vector<int>& requiredSignals) {
        vector<vector<pair<int, int>>> adj(n);

        for(auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<long long> ans(n, -1);
        vector<int> cnt(n, 0);

        // {arrival time, node}
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        ans[0] = 0;

        for(auto [v, delay] : adj[0]) {
            pq.push({delay, v});
        }

        while(!pq.empty()) {
            auto [time, u] = pq.top();
            pq.pop();

            if(ans[u] != -1) continue;

            cnt[u]++;

            if(cnt[u] == requiredSignals[u]) {
                ans[u] = time;

                for(auto [v, delay] : adj[u]) {
                    if(ans[v] == -1) {
                        pq.push({time + delay, v});
                    }
                }
            }
        }
        return ans;
    }
};