class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool> vis(26, false);
        vector<int>count(26, 0);
        stack<char>st;
        string result;
        for(char ch : s) {
            count[ch - 'a']++;
        }
        for(char ch : s) {
            count[ch - 'a']--;
            if(vis[ch - 'a']) continue;
            while(!st.empty() && st.top() > ch && count[st.top() - 'a'] > 0) {
                vis[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(ch);
            vis[ch - 'a'] = true;
        }
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};