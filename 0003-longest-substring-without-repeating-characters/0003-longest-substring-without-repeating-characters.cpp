class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int l=0;
        int r=0;
        int ans=0;
        while(r<s.size()){
            if(!st.count(s[r])){
                ans=max(ans,r-l+1);
                st.insert(s[r]);
                r++;
            }
            else{
                st.erase(s[l]);
                l++;
            }
        }
        return ans;
    }
};