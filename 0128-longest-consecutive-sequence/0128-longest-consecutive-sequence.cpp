class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>set(nums.begin(), nums.end());
        int size = nums.size();
        int ans = 0;
        for(auto ele : set) {
            int count = 0;
            if(set.find(ele - 1) == set.end()) {
                count = 0;
                while(set.find(ele) != set.end()) {
                    ele++;
                    count++;
                }
            }
            ans = max(ans, count);

        }
        return ans;
    }
};