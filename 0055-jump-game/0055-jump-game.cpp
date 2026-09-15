class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far = 0;
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            if(i > far) return false;
            far = max(far, nums[i] + i);
            if(far >= size - 1) {
                return true;
            }
        }
        return true;
    }
};