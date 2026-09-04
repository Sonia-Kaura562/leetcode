class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int l = 0, r = size - 1;
        int leftMax = height[0];
        int rightMax = height[size - 1];
        int total = 0;
        while(l < r) {
            leftMax = max(height[l], leftMax);
            rightMax = max(height[r], rightMax);
            if(leftMax <= rightMax) {
                total += leftMax - height[l];
                l++;
            }
            else {
                total += rightMax - height[r];
                r--;
            }
        }
        return total;
    }
};