class Solution {
private:
    void bfs(vector<vector<int>>& adj, vector<int>& indegree, vector<int>& order, queue<int>& q) {
        while(!q.empty()) {
            int fr = q.front();
            order.push_back(fr);
            q.pop();
            for(int i = 0; i < adj[fr].size(); i++) {
                int b = adj[fr][i];
                indegree[b]--;
                if(!indegree[b]) {
                    q.push(b);
                }
            }
        }
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses, 0);
        vector<int>order;
        queue<int>q;
        int size = prerequisites.size();
        for(int i = 0; i < size; i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        
        for(int i = 0; i < numCourses; i++) {
            if(!indegree[i]) {
                q.push(i);
            }
        }
        bfs(adj, indegree, order, q);
        return (order.size() == numCourses) ? order : vector<int>{};
        
    }
};