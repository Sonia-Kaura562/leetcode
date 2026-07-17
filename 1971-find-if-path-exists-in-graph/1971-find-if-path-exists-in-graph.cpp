class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int>q;
        q.push(source);
        vector<int>vis(n, 0);
        vis[source] = 1;
        while(!q.empty()) {
            int fr = q.front();
            q.pop();
            if(fr == destination) return true;
            for(int i = 0; i < adj[fr].size(); i++) {
                if(!vis[adj[fr][i]]) {
                  vis[adj[fr][i]] = 1;
                  q.push(adj[fr][i]); } 
            }
        }
        return false;
    }
};
