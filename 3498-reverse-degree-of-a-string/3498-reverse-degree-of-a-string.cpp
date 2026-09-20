class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int i = 0; i < s.size(); i++) {
            int n = 'a' - s[i] + 26;
            sum += (i + 1)*n;
        }
        return sum;
    }
};