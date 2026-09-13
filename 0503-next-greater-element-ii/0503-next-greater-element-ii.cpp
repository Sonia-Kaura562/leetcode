class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        for(int i = nums.size() - 1; i >=0; i--) {
            while(!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            st.push(nums[i]);
        }
        vector<int> result(nums.size());
        for(int i = nums.size() - 1; i >=0; i--) {
            while(!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            result[i] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }
        return result;
    }
};