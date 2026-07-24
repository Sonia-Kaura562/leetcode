class Solution {
public:
    int maxArea(vector<int>& height) {
        // brute force

        /*int area = 0;
        for(int i = 0; i < height.size()- 1; i++) {
            for(int j = i + 1; j < height.size(); j++) {
                int h = min(height[i], height[j]);
                int w = j - i;
                area = max(area, h*w);
            }
         }*/
        
        // optimal approach
        int area = 0;
        int i = 0;
        int j = height.size() - 1;
        while(i < j) {
            int w = j - i;
            int h = min(height[i], height[j]);
            area = max(area, w*h);
            if(height[i] <= height[j]) i++;
            else j--;
        }
        return area;
    }
};