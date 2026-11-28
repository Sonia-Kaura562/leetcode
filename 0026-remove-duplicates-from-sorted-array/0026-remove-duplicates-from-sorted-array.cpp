class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int j = 0;
        for(int i = 1; i < size; i++) {
            if(nums[j] != nums[i]) {
                nums[++j] = nums[i];
            }
        }
        return j+1;
    }
};