class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> st;
        for(auto i : nums) {
            st.insert(i);
        }
        int j = 0;
        for(auto i : st) {
            nums[j++] = i;
        }
        sort(nums.begin(), nums.begin() + st.size());
        return st.size();
    }
};