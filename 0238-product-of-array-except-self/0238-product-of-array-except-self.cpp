class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> prePro(size);
        vector<int> sufPro(size);
        vector<int>ans(size);
        prePro[0] = sufPro[size - 1] = 1;
        for(int i = 1; i < size; i++) {
            int pre = prePro[i - 1];
            int preNum = nums[i - 1];
            prePro[i] = pre*preNum;
        }

        for(int i = size - 2; i >= 0; i--) {
            int nex = sufPro[i + 1];
            int nexNum = nums[i + 1];
            sufPro[i] = nex*nexNum;
        }
        for(int i = 0; i < size; i++) {
            ans[i] = prePro[i]*sufPro[i];
        }

        return ans;
    }
};