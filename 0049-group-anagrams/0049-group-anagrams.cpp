class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> temp(strs);
        unordered_map<string, vector<string>>map;
        for(int i = 0; i < temp.size(); i++) {
            sort(temp[i].begin(), temp[i].end());
            map[temp[i]].push_back(strs[i]);
        }

        vector<vector<string>>result;
        for (auto &it : map) {
            result.push_back(it.second);
        }
        return result;
    }
};