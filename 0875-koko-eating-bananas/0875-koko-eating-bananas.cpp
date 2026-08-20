class Solution {
public:
    bool possible(vector<int>& piles, int h, int mid) {
        long long total = 0;
        int size = piles.size();
        for(int i = 0; i < size; i++) {
            total += ceil(piles[i]*1.0 / mid * 1.0);
        }

        return total <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = INT_MAX;
        int low = 1;
        int high = 1;
        for(int i = 0; i < piles.size(); i++) {
            if(high < piles[i])
                high = piles[i];
        }
        while(low <= high) {
            int mid = (low + high)/2;
            if(possible(piles, h, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};