class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int>lps(needle.size(), 0);
        int len = 0;
        int i = 1;
        while( i < needle.size()) {
            if(needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if(len != 0) {
                    len = lps[len - 1];
                }
                else i++; 
            }
        }

        int n = haystack.size();
        int m = needle.size();
        int k = 0;
        int j = 0;
        while(k < n and j < m) {
            if(haystack[k] == needle[j]) {
                k++;
                j++;
            }
            else {
                if(j != 0) {
                    j = lps[j - 1];
                }
                else k++;
            }
        }
        if(j == m) return abs(j - k);
        return -1;
    }
};