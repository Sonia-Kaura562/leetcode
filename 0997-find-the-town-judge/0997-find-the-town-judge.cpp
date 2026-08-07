class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int size = trust.size();
        vector<int> adj(n + 1, 0);
        vector<int> indegree(n + 1, 0);
        for(auto it : trust) {
            adj[it[0]]++;
            indegree[it[1]]++;
        }

        for(int i = 1; i < n + 1; i++) {
            if(indegree[i] == n - 1) {
                if(!adj[i]) {
                    return i;
                }
            }
        }
        return -1;
    }
};