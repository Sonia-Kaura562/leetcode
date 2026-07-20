class Solution {
private: 
    bool dfs(vector<vector<int>>& adj, vector<int>& vis, int node) {
        for(int i = 0; i < adj[node].size(); i++) {
            if(!vis[adj[node][i]]) {
                vis[adj[node][i]] = 2;
                //visPath[adj[node][i]] = 1;
                if(!dfs(adj, vis, adj[node][i])) return false;
                vis[adj[node][i]] = 1;
            }
            else {
                if(vis[adj[node][i]] == 2) {
                        return false;
                }
            }
        }
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //int vis [numCourses] = {0};
        if(numCourses == 0 or numCourses == 1) return true;
        if(prerequisites.size() == 0) return true;
        vector<int> vis(numCourses, 0);
        //vector<int> visPath(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for(int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i = 0; i < numCourses; i++) {
            if(vis[i] == 0) {
                vis[i] = 2;
                if(!dfs(adj, vis, i)) return false;
                vis[i] = 1;
            }
        }
        
        return true;
    }
};