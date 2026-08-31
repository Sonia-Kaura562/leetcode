class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        vector<int> leftMax(size, 0);
        vector<int> rightMax(size, 0);
        for(int i = 1; i < size; i++) {
            leftMax[i] = max(height[i - 1], leftMax[i - 1]);
        }
        for(int i = size - 2; i >= 0; i--) {
            rightMax[i] = max(height[i + 1], rightMax[i + 1]);
        }
        int sum = 0;
        for(int i = 1; i < size - 1; i++) {
            //if(height[i] < leftMax[i] or height[i] < rightMax[i]) {
                int left = leftMax[i];
                int right = rightMax[i];
                sum += max(0, min(left, right) - height[i]);
            //}
        }
        return sum;
    }
};