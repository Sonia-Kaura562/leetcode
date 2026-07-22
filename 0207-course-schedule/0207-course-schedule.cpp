class Solution {
private:
    void dfs(vector<vector<int>>& adj, vector<int>& indegree, vector<int>& pathvisited, int & processed, int curr) {
        for(int i = 0; i < adj[curr].size(); i++) {
            int fr = adj[curr][i];
            indegree[fr]--;
            if(!indegree[fr] and !pathvisited[fr]) {
                processed++;
                pathvisited[fr] = 1;
                dfs(adj, indegree, pathvisited, processed, fr);
            }
        }
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int>indegree(numCourses, 0);
        vector<int>pathvisited(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        int processed = 0;
        for(int i = 0; i < numCourses; i++) {
            if(!indegree[i] and !pathvisited[i]) {
                processed++;
                pathvisited[i] = 1;
                dfs(adj, indegree, pathvisited, processed, i);
            }
        }
        return processed == numCourses;
    }
};