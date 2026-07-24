class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        int size = height.size();
        vector<int>leftMax(size, 0);
        vector<int>rightMax(size, 0);
        rightMax[size - 1]= height[size - 1]; 
        leftMax[0] = height[0];
        for(int i = size - 2; i >= 0; i--) {
            rightMax[i] = max(height[i], rightMax[i+1]);
        }
        for(int i = 1; i < height.size(); i++) {
            leftMax[i] = max(height[i], leftMax[i-1]);
        }
        for(int i = 0; i < size; i++) {
            result += (min(leftMax[i], rightMax[i]) - height[i]);
        }
        return result;
    }
};