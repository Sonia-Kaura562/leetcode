class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& vis, vector<int>& visPath, int node) {
        for(int i = 0; i < adj[node].size(); i++) {
            if(!vis[adj[node][i]]) {
                vis[adj[node][i]] = 1;
                visPath[adj[node][i]] = 1;
                if(!dfs(adj, vis, visPath, adj[node][i])) return false;
                visPath[adj[node][i]] = 0;
            }
            else {
                if(visPath[adj[node][i]] == 1) {
                        return false;
                }
            }
        }
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //int vis [numCourses] = {0};
        if(numCourses == 0 or numCourses == 1) return true;
        if(prerequisites.size() == 0) return true;
        vector<int> vis(numCourses, 0);
        vector<int> visPath(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for(int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i = 0; i < numCourses; i++) {
            if(vis[i] == 0) {
                int node = i;
                vis[node] = 1;
                visPath[node] = 1;
                if(!dfs(adj, vis, visPath, node)) return false;
                visPath[node] = 0;
            }
        }
        
        return true;
    }
};