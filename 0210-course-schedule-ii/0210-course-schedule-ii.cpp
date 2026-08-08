class Solution {
private:
    void dfs(int curr, vector<vector<int>>& adj, vector<int>& indegree, vector<int>& order, vector<int>& vis) {
        vis[curr] = 1;
        order.push_back(curr);
        for(int i = 0; i < adj[curr].size(); i++) {
            int b = adj[curr][i];
            indegree[b]--;
            if(!indegree[b] and !vis[b]) {
                dfs(b, adj, indegree, order, vis);
            }
        }
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses, 0);
        vector<int>order;
        vector<int>vis(numCourses, 0);
        int size = prerequisites.size();
        for(int i = 0; i < size; i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        
        for(int i = 0; i < numCourses; i++) {
            if(!indegree[i] and !vis[i]) {
                dfs(i, adj, indegree, order, vis);
            }
        }
        return (order.size() == numCourses) ? order : vector<int>{};
    }
};