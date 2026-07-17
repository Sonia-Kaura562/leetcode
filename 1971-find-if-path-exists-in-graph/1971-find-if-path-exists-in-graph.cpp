class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int>q;
        q.push(source);
        vector<int>vis(n, 0);
        vis[source] = 1;
        while(!q.empty()) {
            int fr = q.front();
            q.pop();
            if(fr == destination) return true;
            for(auto it : adj[fr]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it); 
                } 
            }
        }
        return false;
    }
};
