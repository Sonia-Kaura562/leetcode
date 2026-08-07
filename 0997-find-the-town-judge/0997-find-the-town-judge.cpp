class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int size = trust.size();
        vector<int> netInOut(n + 1, 0);
        for(auto it : trust) {
            netInOut[it[0]]--;
            netInOut[it[1]]++;
        }
        for(int i = 1; i < netInOut.size(); i++) {
            if(netInOut[i] == n-1) 
                return i; 
        }
        return -1;
    }
};