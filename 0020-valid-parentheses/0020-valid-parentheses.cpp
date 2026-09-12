class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        int size = s.size();
        for(auto i : s) {
           if(i == '(' or i == '{' or i == '[') {
            st.push(i);
           }
           else {
            if(st.empty()) return false;
            if(i == ')' and st.top() != '(') return false;
            if(i == '}' and st.top() != '{') return false;
            if(i == ']' and st.top() != '[') return false;
            st.pop();
           }
        }
        return st.empty();
    }
};