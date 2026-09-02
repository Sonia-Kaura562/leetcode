class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int size = nums.size();
        vector<int> result(size);
        for(int i = 2*size - 2; i >= 0; i--) {
            int index = i%size;
            while(!st.empty() && st.top() <= nums[index]) {
                st.pop();
            }
            if( i < size) {
                result[i] = st.empty() ? -1 : st.top();
            }
            st.push(nums[index]);
        }
        return result;
    }
};