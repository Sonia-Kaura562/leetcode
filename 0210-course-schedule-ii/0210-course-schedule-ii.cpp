class Solution {
private:
    void bfs(int i,vector<int>& vis, vector<vector<int>>& adj, vector<int>& indegree, vector<int>& order) {
        queue<int>q;
        q.push(i);
        while(!q.empty()) {
            int fr = q.front();
            order.push_back(fr);
            q.pop();
            for(int i = 0; i < adj[fr].size(); i++) {
                int b = adj[fr][i];
                indegree[b]--;
                if(!indegree[b]) {
                    vis[b] = 1;
                    q.push(b);
                }
            }
        }
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses, 0);
        vector<int>vis(numCourses, 0);
        vector<int>order;
        int size = prerequisites.size();
        for(int i = 0; i < size; i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i] and !indegree[i]) {
                vis[i] = 1;
                bfs(i, vis, adj, indegree, order);
            }
        }
        return (order.size() == numCourses) ? order : vector<int>{};
        
    }
};