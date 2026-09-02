class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int size = prices.size();
        vector<int> result(size);
        stack<int> st;
        for(int i = size - 1; i >= 0; i--) {
            while(!st.empty() && st.top() > prices[i]) {
                st.pop();
            }
            result[i] = st.empty() ? prices[i] : (prices[i] - st.top());
            st.push(prices[i]);
        }
        return result;
    }
};