class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(vector<int> num : prerequisites) {
            int d = num[0];
            int s = num[1];
            adj[s].push_back(d);
            indegree[d]++;
        }

        queue<int>q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
               q.push(i);
            }
        }
        int c = 0;
        while(!q.empty()) {
            int course = q.front();
            q.pop();
            c++;
            for(int num : adj[course]) {
                indegree[num]--;
                if(indegree[num] == 0) {
                    q.push(num);
                }
            }
        }
        return c == numCourses;
    }
};