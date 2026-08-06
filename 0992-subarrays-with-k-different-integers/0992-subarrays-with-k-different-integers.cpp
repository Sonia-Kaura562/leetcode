class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int size = nums.size();
        int l = 0, r = 0, ans = 0;
        while( r < size) {
           map[nums[r]]++;
           while(map.size() > k) {
            map[nums[l]]--;
            if(map[nums[l]] == 0) {
                map.erase(nums[l]);
            }
            l++;
        }

        ans += (r-l+1);
        r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};