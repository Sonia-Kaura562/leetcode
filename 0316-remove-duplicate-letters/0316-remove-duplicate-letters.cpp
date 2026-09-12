class Solution {
    public:
     string removeDuplicateLetters(string s) {
        int size = s.size();
        vector<int>count(27, 0);
        vector<bool>vis(27, 0);
        stack<char>st;
        for(int i = 0; i < size; i++) {
            int k = s[i] - 'a';
            count[k]++;
        }

        for(auto i : s) {
            if(vis[i - 'a'] == 1) {
                count[i - 'a']--;
                continue;
            }
            while(!st.empty() and st.top() > i) {
                if(count[st.top() - 'a'] <= 0) break;
                vis[st.top() - 'a'] = 0;
                st.pop();
            }
            st.push(i);
            vis[i - 'a'] = 1;
            count[i - 'a']--;
        }
        string ans;
        vector<char>res;
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        for(auto i : res) {
            ans += i;
        }
        return ans;
    }
};