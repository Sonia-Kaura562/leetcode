class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string left = "";
        char middle = '\0';

        for (int i = 0; i < 26; i++) {
            left += string(freq[i] / 2, char('a' + i));

            if (freq[i] % 2)
                middle = char('a' + i);
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (middle == '\0')
            return left + right;

        return left + middle + right;
    }
};