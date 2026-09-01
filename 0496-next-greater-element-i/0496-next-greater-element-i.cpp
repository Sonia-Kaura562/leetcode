class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int size2 = nums2.size();
        int size1 = nums1.size();
        vector<int>result(size1);
        unordered_map<int, int> mp;
        for(int i = 0; i < nums1.size(); i++) {
            mp[nums1[i]] = i;
        }
        for(int i = size2 - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            int greater = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
            if(mp.find(nums2[i]) != mp.end()) {
                result[mp[nums2[i]]] = greater;
            }
        }
        return result;
    }
};