class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int size = trust.size();
        vector<vector<int>> adj(n + 1);
        vector<int> indegree(n + 1, 0);
        for(int i = 0; i < size; i++) {
            int a = trust[i][0];
            int b = trust[i][1];
            adj[a].push_back(b);
            indegree[b]++;
        }

        for(int i = 1; i < n + 1; i++) {
            if(indegree[i] == n - 1) {
                if(adj[i].size() == 0) {
                    return i;
                }
            }
        }
        return -1;
    }
};