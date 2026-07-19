class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(vector<int> num: prerequisites) {
            int s = num[1];
            int d = num[0];
            adj[s].push_back(d);
            indegree[d]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        int c = 0;
        vector<int> output;
        while(!q.empty()) {
            int course = q.front();
            c++;
            
            q.pop();
            for(int num : adj[course]) {
                indegree[num]--;
                if(indegree[num] == 0) q.push(num);
            }
            output.push_back(course);
        }
        if(c == numCourses) return output;
        return {};
    }
};