class Solution {
private:
    int bfs(vector<vector<int>>& adj, vector<int>& indegree, queue<int>& q) {
        int processed = 0;
        while(!q.empty()) {
            int fr = q.front();
            q.pop();
            processed++;
            for(int i = 0; i < adj[fr].size(); i++) {
                int curr = adj[fr][i];
                indegree[curr]--;
                if(indegree[curr] == 0) { 
                    q.push(curr);
                }    
            }
        }
        return processed;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses == 0 or numCourses == 1) return true;
        queue<int>q;
        vector<int>indegree(numCourses, 0);
        vector<vector<int>>adj(numCourses); 
        for(int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i = 0; i < prerequisites.size(); i++) {
            indegree[prerequisites[i][0]]++;
        }
        int processed = 0;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        processed = bfs(adj, indegree, q);
        return processed == numCourses;
    }
};