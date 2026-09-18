class Solution {
public:
    int count = 0;
    void solve(vector<int>& nums, int low, int mid, int high) {
        // int i = low;
        // int j = mid + 1;
        // while(i <= mid && j <= high) {
        //     if(nums[i] > 2*nums[j]) {
        //         j++;
        //     }
        //     count += mid + 1 - 
        // }
        int right = mid + 1;
        for(int i = low; i < mid + 1; i++) {
            while(right <= high and nums[i]*1.0 > 2*1.0*nums[right]) {
                right++;
            }
            count += (right -(mid + 1));
        }
    }
    void mergesort(vector<int>& nums, int low, int mid, int high) {
        int i = low;
        int j = mid + 1;
        vector<int>temp(high - low + 1);
        int k = 0;
        solve(nums, low, mid, high);
        while(i <= mid && j <= high) {
            if(nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            }
            else {
                temp[k++] = nums[j++];
            }
        }
        while(j <= high) {
            temp[k] = nums[j];
            j++;
            k++;
        }
        
        
        while(i <= mid) {
            temp[k] = nums[i];
            i++;
            k++;
        }
        

        for(int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }

    }
    void merge(vector<int>& nums, int low, int high) {
        if(low < high) {
            int mid = (high + low)/2; 
            merge(nums, low, mid);
            merge(nums, mid + 1, high);
            mergesort(nums, low, mid, high);
        }
    }
    int reversePairs(vector<int>& nums) {
        int size = nums.size();
        merge(nums, 0, size - 1);
        return count;
    }
};