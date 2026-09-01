class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int size = nums2.size();
        vector<int>temp(size);
        vector<int>result(nums1.size());
        unordered_map<int, int> mp;
        for(int i = 0; i < nums1.size(); i++) {
            mp[nums1[i]] = i;
        }
        for(int i = size - 1; i >= 0; i--) {
            while(!st.empty() && st.top() < nums2[i]) {
                st.pop();
            }
            if(!st.empty()) temp[i] = st.top();
            else temp[i] = -1;
            st.push(nums2[i]);
            if(mp.find(nums2[i]) != mp.end()) {
                result[mp[nums2[i]]] = temp[i];
            }
        }
        return result;
    }
};