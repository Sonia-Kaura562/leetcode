class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int size = intervals.size();
        int curr = 0;
        for(int i = 1; i < size; i++) {
            if(ans[curr][1] >= intervals[i][0]) {
                ans[curr][1] = max(ans[curr][1], intervals[i][1]);
            }
            else {
                ans.push_back(intervals[i]);
                curr++;
            }
        }
        return ans;
    }
};