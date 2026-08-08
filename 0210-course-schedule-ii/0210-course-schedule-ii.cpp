class Solution {
private:
    void dfs(int curr, vector<vector<int>>& adj, vector<int>& order, vector<int>& vis) {
        vis[curr] = 2;
        for(int i = 0; i < adj[curr].size(); i++) {
            int b = adj[curr][i];
            if(vis[b] == 2) {
                //dfs(b, adj, order, vis);
                order = vector<int>{};
                return;
            }
            else if(!vis[b]) {
                dfs(b, adj, order, vis);
                if(order == vector<int>{}) return;
            }
        }
        vis[curr] = 1;
        order.push_back(curr);
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
                dfs(i, adj, order, vis);
                vis[i] = 1;
                if(order == vector<int>{}) 
                    return order;
            }
        }
        reverse(order.begin(), order.end());
        //return (order.size() == numCourses) ? order : vector<int>{};
        return order;
    }
};