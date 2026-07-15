class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&arr, vector<vector<int>> &ans, vector<int>&temp, int index) {
        if(index >= arr.size()) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(arr[index]);
        solve(arr, ans, temp, index + 1);
        temp.pop_back();
        solve(arr, ans, temp, index + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        solve(nums, ans, temp, 0);
        return ans;
    }
};