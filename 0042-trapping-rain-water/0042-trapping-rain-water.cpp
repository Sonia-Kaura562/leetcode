class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int result = 0;
        vector<int>rightMax(size, 0);
        rightMax[size - 1] = height[size - 1];
        for(int i = size - 2; i >= 0; i--) {
            rightMax[i] = max(height[i], rightMax[i + 1]);
        }
        int leftMax = height[0];
        for(int i = 0; i < size; i++) {
            leftMax = max(leftMax, height[i]);
            if(height[i] < leftMax && height[i] < rightMax[i]) {
                result += min(leftMax, rightMax[i]) - height[i];
            }
        }
        return result;
    }
};