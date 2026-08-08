class Solution {
private:
    bool dfs(int curr, vector<vector<int>>& adj, vector<int>& order, vector<int>& vis) {
        vis[curr] = 2;
        for(int i = 0; i < adj[curr].size(); i++) {
            int b = adj[curr][i];
            if(vis[b] == 2) {
                return false;
            }
            else if(!vis[b]) {
                if(!dfs(b, adj, order, vis)) return false;
            }
        }
        order.push_back(curr);
        vis[curr] = 1;
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>order;
        vector<int>vis(numCourses, 0);
        int size = prerequisites.size();
        for(int i = 0; i < size; i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[b].push_back(a);
        }
        
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                if(!dfs(i, adj, order, vis)) return {};
            }
        }
        reverse(order.begin(), order.end());
        //return (order.size() == numCourses) ? order : vector<int>{};
        return order;
    }
};