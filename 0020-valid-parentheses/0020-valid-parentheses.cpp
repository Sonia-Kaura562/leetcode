class Solution {
public:
    bool isValid(string s) {
        char arr[3][2] = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
        unordered_map<char, char> mp;
        mp[')'] = '(';
        mp['}'] = '{';
        mp[']'] = '[';
        stack<int>st;
        int size = s.size();
        for(auto i : s) {
           if(i == ')' or i == '}' or i == ']') {
            if(st.empty() or st.top() != mp[i]) {
                return false;
            }
            st.pop();
           }
           else {
            st.push(i);
           }
        }
        return st.empty();
    }
};