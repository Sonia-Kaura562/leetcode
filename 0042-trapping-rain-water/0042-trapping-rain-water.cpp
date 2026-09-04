class Solution {
public:
    int trap(vector<int>& height) {

        stack<int> st;
        int water = 0;

        for(int i = 0; i < height.size(); i++) {

            while(!st.empty() &&
                  height[i] > height[st.top()]) {

                int bottom = st.top();
                st.pop();

                // No left boundary
                if(st.empty())
                    break;

                int left = st.top();

                int width = i - left - 1;

                int waterHeight =
                    min(height[left], height[i])
                    - height[bottom];

                water += width * waterHeight;
            }

            st.push(i);
        }

        return water;
    }
};