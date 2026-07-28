class Solution {
public:
    string smallestPalindrome(string s) {
        int size = s.size();
        int half = size/2;
        sort(s.begin(), s.begin() + half);
        int i = 0; 
        int j = size-1;
        while(i <= j) {
            s[j] = s[i];
            i++;
            j--;
        }

        return s;
    }
};